#pragma once
#include "Core.h"

struct DirectionalLight{
    //Direction of light
    glm::vec3 mDirection;
    //Diffuse color
    glm::vec3 mDiffuseColor;
    //Specular color
    glm::vec3 mSpecColor;
};

class Renderer{
public:
    Renderer(class Game* game);
    ~Renderer();
    
    bool Init(float screenWidth, float screenHeight);
    void Shutdown();
    void UnloadData();

    void Draw();

    class Texture2D* GetTexture(const std::string& fileName);
    class Mesh* GetMesh(std::string& fileName);

    void SetViewMatrix(const glm::mat4& view) { mView = view;}

    void SetAmbientLight(const glm::vec3& ambient) { mAmbientLight = ambient;}
    DirectionalLight& GetDirectionalLight() { return mDirLight;}

    float GetScreenWidth() const { return mScreenWidth;}
    float GetScreenHeight() const { return mScreenHeight;}

private:
    bool LoadShaders();
    void CreateSpriteVerts();
    void SetLightUniforms(class Shader* shader);
    glm::mat4 CreateSimpleViewProj(float width, float height);

    //sprite shader
    class Shader* mSpriteShader;
    //sprite vertex array
    class VertexArray* mSpriteVerts;
    //Mesh shdaer
    class Shader* mMeshShader;

    //game
    class Game* mGame;

    //view/projection for 3D shaders
    glm::mat4 mView, mProjection;
    //width/height of screen
    float mScreenWidth, mScreenHeight;

    //Lighting data
    glm::vec3 mAmbientLight;
    DirectionalLight mDirLight;
};