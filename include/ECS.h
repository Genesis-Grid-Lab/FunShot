#pragma once
#include "Core.h"
#include "Data.h"
#include "Mesh.h"
#include "Vertex.h"
struct SpriteComponent{
    inline SpriteComponent(const SpriteComponent &) = default;
    inline SpriteComponent() = default;

    Texture2D Texture;

    void Draw(Shader* shader,Transform2D& transform){

        shader->SetActive();
        // model = glm::translate(model, glm::vec3(transform.Translate, 0.0f));  // first translate (transformations are: scale happens first, then rotation, and then final translation happens; reversed order)
        glm::mat4 model = CreateTranslation(glm::vec3(transform.Translate, 0));

        // model = glm::translate(model, glm::vec3(0.5f * transform.Scale.x, 0.5f * transform.Scale.y, 0.0f)); // move origin of rotation to center of quad
        // model = glm::rotate(model, glm::radians(transform.Rotation), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate
        // model = glm::translate(model, glm::vec3(-0.5f * transform.Scale.x, -0.5f * transform.Scale.y, 0.0f)); // move origin back

        glm::vec3 scale = glm::vec3(transform.Scale.x, transform.Scale.y, 1.0f);
        model *= CreateScale(scale);
        model = glm::scale(model, glm::vec3(Texture.GetWidth(), Texture.GetHeight(), 1.0f)); // last scale

        shader->SetMatrixUniform("uWorldTransform", model);
        Texture.SetActive();
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

struct Camera3DComponent{
    inline Camera3DComponent(const Camera3DComponent&) = default;
    inline Camera3DComponent() = default;
    Camera3D Camera;
};

struct MeshComponent{
    inline MeshComponent(const MeshComponent&) = default;
    inline MeshComponent() = default;
    Mesh mMesh;

    void Draw(Shader* shader, Transform3D& transform ){
        shader->SetActive();
        glm::mat4 model = glm::mat4(1.0f);
        model = CreateScale(transform.Scale);
        model *= CreateFromQuaternion(transform.test);
        model *= CreateTranslation(transform.Translate);
        shader->SetMatrixUniform("uWorldTransform", model);
        shader->SetFloatUniform("uSpecPower", mMesh.GetSpecPower());
        Texture2D* t = mMesh.GetTexture(0);
        // mMesh.
        if(t){
            FN_INFO("texactive");
            t->SetActive();
        }

        //set mesh vertex array as active
        VertexArray* va = mMesh.GetVertexArray();
        va->SetActive();
        glDrawElements(GL_TRIANGLES, va->GetNumIndices(), GL_UNSIGNED_INT, nullptr);
    }

private:
    glm::mat4 CreateFromQuaternion(glm::quat &q){
        float mat[4][4];

    	mat[0][0] = 1.0f - 2.0f * q.y * q.y - 2.0f * q.z * q.z;
    	mat[0][1] = 2.0f * q.x * q.y + 2.0f * q.w * q.z;
    	mat[0][2] = 2.0f * q.x * q.z - 2.0f * q.w * q.y;
    	mat[0][3] = 0.0f;

    	mat[1][0] = 2.0f * q.x * q.y - 2.0f * q.w * q.z;
    	mat[1][1] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.z * q.z;
    	mat[1][2] = 2.0f * q.y * q.z + 2.0f * q.w * q.x;
    	mat[1][3] = 0.0f;

    	mat[2][0] = 2.0f * q.x * q.z + 2.0f * q.w * q.y;
    	mat[2][1] = 2.0f * q.y * q.z - 2.0f * q.w * q.x;
    	mat[2][2] = 1.0f - 2.0f * q.x * q.x - 2.0f * q.y * q.y;
    	mat[2][3] = 0.0f;

    	mat[3][0] = 0.0f;
    	mat[3][1] = 0.0f;
    	mat[3][2] = 0.0f;
    	mat[3][3] = 1.0f;

        glm::mat4 temp2;

        memcpy(glm::value_ptr(temp2), mat, sizeof(mat));

    return temp2;
    }
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
