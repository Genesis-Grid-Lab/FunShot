#include "Renderer.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Game.h"
#include "ResourceManager.h"
#include "ECS.h"

Renderer::Renderer(Game* game) : mGame(game), mSpriteShader(nullptr), mMeshShader(nullptr){   
}

Renderer::~Renderer(){}

bool Renderer::Init(float screenWidth, float screenHeight){
    mScreenWidth = screenWidth;
    mScreenHeight = screenHeight;

    // initialize opengl
    if (glewInit() != GLEW_OK) {
      FN_FATAL("failed to init glew!");
      return false;
    }

    glewExperimental = GL_TRUE;

    glViewport(0,0, mScreenWidth, mScreenHeight);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //Make sucre we can create/compile shaders
    if(!LoadShaders()){
        FN_ERROR("Failed to load shaders");
        return false;
    }

    // Create quad for drawing sprites
    CreateSpriteVerts();

    return true;
}

void Renderer::Shutdown(){
    delete mSpriteVerts;
    delete mSpriteShader;
    delete mMeshShader;
}

void Renderer::UnloadData(){
    ResourceManager::Clear();
}

void Renderer::Draw(){
    //set the clear color to light gray
    glClearColor(0.86, 0.86, 0.86, 1);
    //clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Draw mesh
    //Enable depth buffering/disable alpha blend
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_BLEND);
    //Set mesh shader active
    ResourceManager::GetShader("PhongShader").Use();
    //Update view-projection matrix
    ResourceManager::GetShader("PhongShader").SetMatrix4("uViewProj", mView * mProjection);
    // // Update lighting uniforms
    // SetLightUniforms(mMeshShader);
    mGame->EnttView<Entity, MeshComponent>([this](auto entity, auto &comp){
        auto &transform = entity.template Get<Transform3DComponent>().Transform;
        comp.Draw(ResourceManager::GetShader("PhongShader"), transform);
    });

    //Draw all prite components
    //Disable deoth buffering
    glDisable(GL_DEPTH_TEST);
    //Enable alpha blending on the color buffer
    glEnable(GL_BLEND);
    glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

    // //set shader/vao as active
    // mSpriteShader->Use();
    ResourceManager::GetShader("SpriteShader").Use();
    mSpriteVerts->SetActive();
    mGame->EnttView<Entity, SpriteComponent>([this](auto entity, auto& comp){
        auto& transform = entity.template Get<Transform2DComponent>().Transform;
        comp.Draw(ResourceManager::GetShader("SpriteShader"), transform);
    });
}

Texture2D* Renderer::GetTexture(const std::string& fileName){
    ResourceManager::GetTexture(fileName);
    return nullptr;
}

Mesh* Renderer::GetMesh(std::string& fileName){
    ResourceManager::GetMesh(fileName);
    return nullptr;
}

bool Renderer::LoadShaders(){
    // //Create sprite shader
    // mSpriteShader = new Shader();
    ResourceManager::LoadShader("Resources/Shaders/basic.vert", "Resources/Shaders/basic.frag", nullptr, "BasicShader");
    Shader SpriteShader = ResourceManager::LoadShader("Resources/Shaders/Sprite.vert","Resources/Shaders/Sprite.frag", nullptr, "SpriteShader").Use();
    SpriteShader.Use();
    //Set the view-projection matrix
    // glm::mat4 viewProj = glm::perspective(glm::radians(45.0f), mScreenWidth / mScreenHeight, 0.1f, 100.0f);
    // glm::mat4 viewProj = glm::ortho(0.0f, mScreenWidth, mScreenHeight, 0.0f, -1.0f, 1.0f);
    // glm::mat4 viewProj = glm::perspective(glm::radians(45.0f), mScreenWidth / mScreenHeight, 0.1f, 100.0f);
    glm::mat4 viewProj = CreateSimpleViewProj(mScreenWidth, mScreenHeight);
    SpriteShader.SetMatrix4("uViewProj", viewProj);

    //create basic mesh shader
    Shader MeshShader = ResourceManager::LoadShader("Resources/Shaders/Phong.vert", "Resources/Shaders/Phong.frag", nullptr, "PhongShader");
    MeshShader.Use();
    mView = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), 
  		   glm::vec3(0.0f, 0.0f, 0.0f), 
  		   glm::vec3(0.0f, 1.0f, 0.0f));
    mProjection = glm::perspectiveFov(glm::radians(70.0f), mScreenWidth, mScreenHeight, 25.0f, 10000.0f);
    MeshShader.SetMatrix4("uViewProj", mView * mProjection);
    ResourceManager::GetShader("BasicShader").SetMatrix4("uViewProj", viewProj);
    return true;
}

void Renderer::CreateSpriteVerts(){
    float vertices[] = {
		-0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 0.f, // top left
		0.5f, 0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 0.f, // top right
		0.5f,-0.5f, 0.f, 0.f, 0.f, 0.0f, 1.f, 1.f, // bottom right
		-0.5f,-0.5f, 0.f, 0.f, 0.f, 0.0f, 0.f, 1.f  // bottom left
	};

	unsigned int indices[] = {
		0, 1, 2,
		2, 3, 0
	};

	mSpriteVerts = new VertexArray(vertices, 4, indices, 6);
}

void Renderer::SetLightUniforms(Shader* shader){
	// Camera position is from inverted view
	// glm::mat4 invView = glm::inverse(mView);
    // glm::vec3 trans = glm::vec3(invView[3]);
	// // invView.Invert();
	// ResourceManager::GetShader("PhongShader").SetVector3f("uCameraPos", trans);
	// // Ambient light
	// ResourceManager::GetShader("PhongShader").SetVector3f("uAmbientLight", mAmbientLight);
	// // Directional light
	// ResourceManager::GetShader("PhongShader").SetVector3f("uDirLight.mDirection",
	// 	mDirLight.mDirection);
	// ResourceManager::GetShader("PhongShader").SetVector3f("uDirLight.mDiffuseColor",
	// 	mDirLight.mDiffuseColor);
	// ResourceManager::GetShader("PhongShader").SetVector3f("uDirLight.mSpecColor",
	// 	mDirLight.mSpecColor);
}

glm::mat4 Renderer::CreateSimpleViewProj(float width, float height){
   float temp[4][4] = {
        { 2.0f/width, 0.0f, 0.0f, 0.0f },
        { 0.0f, 2.0f/height, 0.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f, 1.0f }
    };

    glm::mat4 temp2;

    memcpy(glm::value_ptr(temp2), temp, sizeof(temp));

    return temp2;
}