#pragma once
#include "Core.h"
#include "Data.h"
#include "Mesh.h"
#include "Vertex.h"
struct SpriteComponent{
    inline SpriteComponent(const SpriteComponent &) = default;
    inline SpriteComponent() = default;

    Texture2D Texture;

    void Draw(Shader& shader,Transform2D& transform){

        shader.Use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, glm::vec3(transform.Translate, 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)
        // model *= CreateTranslation(glm::vec3(transform.Translate, 0));

        model = glm::translate(model, glm::vec3(0.5f * transform.Scale.x, 0.5f * transform.Scale.y, 0.0f)); // move origin of rotation to center of quad
        model = glm::rotate(model, glm::radians(transform.Rotation), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
        model = glm::translate(model, glm::vec3(-0.5f * transform.Scale.x, -0.5f * transform.Scale.y, 0.0f)); // move origin back

        model *= CreateScale(glm::vec3(transform.Scale.x, transform.Scale.y, 1.0f));
        model = glm::scale(model, glm::vec3(Texture.Width, Texture.Height, 1.0f)); // last scale

        shader.SetMatrix4("uWorldTransform", model);
        Texture.Bind();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
    }

private:
    glm::mat4 CreateTranslation(const glm::vec3& trans){
        float temp[4][4] = {
            { 1.0f, 0.0f, 0.0f, 0.0f },
			{ 0.0f, 1.0f, 0.0f, 0.0f },
			{ 0.0f, 0.0f, 1.0f, 0.0f },
			{ trans.x, trans.y, trans.z, 1.0f }
        };

        glm::mat4 temp2;

        memcpy(glm::value_ptr(temp2), temp, sizeof(temp));

     return temp2;
    }

    glm::mat4 CreateScale(glm::vec3& scale)
	{
		float temp[4][4] =
		{
			{ scale.x, 0.0f, 0.0f, 0.0f },
			{ 0.0f, scale.y, 0.0f, 0.0f },
			{ 0.0f, 0.0f, scale.z, 0.0f },
			{ 0.0f, 0.0f, 0.0f, 1.0f }
		};
		
	glm::mat4 temp2;

        memcpy(glm::value_ptr(temp2), temp, sizeof(temp));

     return temp2;
    }
};

struct Transform2DComponent{
    inline Transform2DComponent(const Transform2DComponent&) = default;
    inline Transform2DComponent() = default;
    Transform2D Transform;
};

struct Transform3DComponent{
    inline Transform3DComponent(const Transform3DComponent&) = default;
    inline Transform3DComponent() = default;
    Transform3D Transform;
};

struct MeshComponent{
    inline MeshComponent(const MeshComponent&) = default;
    inline MeshComponent() = default;
    Mesh mMesh;

    void Draw(Shader& shader, Transform3D& transform ){
        shader.Use();
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, transform.Translate);  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)

        model = glm::translate(model, glm::vec3(0.5f * transform.Scale.x, 0.5f * transform.Scale.y, 0.0f)); // move origin of rotation to center of quad
        model = glm::rotate(model, glm::radians(transform.Rotation), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
        model = glm::translate(model, glm::vec3(-0.5f * transform.Scale.x, -0.5f * transform.Scale.y, 0.0f)); // move origin back

        model = glm::scale(model, transform.Scale); // last scale
        shader.SetMatrix4("uWorldTransform", model);
        shader.SetFloat("uSpecPower", mMesh.GetSpecPower());
        Texture2D* t = mMesh.GetTexture(0);

        if(t){
            t->Bind();
        }

        //set mesh vertex array as active
        VertexArray* va = mMesh.GetVertexArray();
        va->SetActive();
        glDrawElements(GL_TRIANGLES, va->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
    }
};

//base entity
class Entity{
public:
    inline Entity(EntityRegistry *registry, EntityID entity)
        : mRegistry(registry), mEnttID(entity){}

    inline Entity(EntityRegistry *registry) : mRegistry(registry){
        mEnttID = mRegistry->create();
    }

    inline virtual ~Entity() = default;
    inline Entity() = default;

    inline operator EntityID() { return mEnttID;}

    inline operator bool() {
        return mRegistry != nullptr && mRegistry->valid(mEnttID);
    }

    inline EntityID ID() { return mEnttID;}

    //++
    template <typename T, typename... Args>
    inline T &Attach(Args &&...args){
        return mRegistry->get_or_emplace<T>(mEnttID, std::forward<Args>(args)...);
    }

    template <typename T>
    inline void Detach(){
        mRegistry->remove<T>(mEnttID);
    }

    inline void Destroy(){
        if(mRegistry){
            mRegistry->destroy(mEnttID);
        }
    }

    template <typename T>
    inline bool Has(){
        return mRegistry != nullptr && mRegistry->all_of<T>(mEnttID);
    }

    template <typename T>
    inline T &Get(){
        return mRegistry->get<T>(mEnttID);
    }

protected:
    EntityRegistry *mRegistry = nullptr;
    EntityID mEnttID = NENTT;
};