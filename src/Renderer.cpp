#include "Renderer.h"
#include "Shader.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Game.h"
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
	mSpriteShader->Unload();
	delete mSpriteShader;
	mMeshShader->Unload();
	delete mMeshShader;
}

void Renderer::UnloadData(){

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
    mMeshShader->SetActive();
    //Update view-projection matrix
    mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
    // Update lighting uniforms
    SetLightUniforms(mMeshShader);
    mGame->EnttView<Entity, MeshComponent>([this](auto entity, auto &comp){
        auto &transform = entity.template Get<Transform3DComponent>().Transform;
        comp.Draw(mMeshShader, transform);
    });

    mGame->EnttView<Entity, Camera3DComponent>([this](auto entity, auto& comp){
        auto& transform = entity.template Get<Transform3DComponent>().Transform;
        comp.Camera.Position = transform.Translate;
        glm::mat4 view = CreateLookAt(comp.Camera.Position, glm::vec3(1,0,0), comp.Camera.Up);
        SetViewMatrix(view);
    });

    //Draw all prite components
    //Disable deoth buffering
    glDisable(GL_DEPTH_TEST);
    //Enable alpha blending on the color buffer
    glEnable(GL_BLEND);
    glBlendEquationSeparate(GL_FUNC_ADD, GL_FUNC_ADD);
    glBlendFuncSeparate(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA, GL_ONE, GL_ZERO);

    // //set shader/vao as active
    mSpriteShader->SetActive();
    mSpriteVerts->SetActive();
    mGame->EnttView<Entity, SpriteComponent>([this](auto entity, auto& comp){
        auto& transform = entity.template Get<Transform2DComponent>().Transform;
        comp.Draw(mSpriteShader, transform);
    });
}

Texture2D* Renderer::GetTexture(const std::string& fileName){
    Texture2D* tex = nullptr;
    tex = new Texture2D();
	if (tex->Load(fileName))
	{
		// mTextures.emplace(fileName, tex);
	}
	else
	{
		delete tex;
		tex = nullptr;
	}
    return tex;
}

Mesh* Renderer::GetMesh(std::string& fileName){
    Mesh* m = nullptr;
    m = new Mesh();
	if (m->Load(fileName, this))
	{
		// mMeshes.emplace(fileName, m);
	}
	else
	{
		delete m;
		m = nullptr;
	}
    return m;
}

bool Renderer::LoadShaders(){
    // //Create sprite shader
    mSpriteShader = new Shader();
    if (!mSpriteShader->Load("Resources/Shaders/Sprite.vert", "Resources/Shaders/Sprite.frag"))
	{
		return false;
	}
    mSpriteShader->SetActive();
    //Set the view-projection matrix
    // glm::mat4 viewProj = glm::perspective(glm::radians(45.0f), mScreenWidth / mScreenHeight, 0.1f, 100.0f);
    // glm::mat4 viewProj = glm::ortho(0.0f, mScreenWidth, mScreenHeight, 0.0f, -1.0f, 1.0f);
    // glm::mat4 viewProj = glm::perspective(glm::radians(45.0f), mScreenWidth / mScreenHeight, 0.1f, 100.0f);
    glm::mat4 viewProj = CreateSimpleViewProj(mScreenWidth, mScreenHeight);
    mSpriteShader->SetMatrixUniform("uViewProj", viewProj);

    //create basic mesh shader
    mMeshShader = new Shader();
	if (!mMeshShader->Load("Resources/Shaders/Phong.vert", "Resources/Shaders/Phong.frag"))
	{
		return false;
	}
    mMeshShader->SetActive();
    // mView = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
  		//    glm::vec3(0.0f, 0.0f, 0.0f),
  		//    glm::vec3(0.0f, 1.0f, 0.0f));
    mView = CreateLookAt(glm::vec3(0), glm::vec3(1,0,0), glm::vec3(0,0,1));
    // mProjection = glm::perspectiveFov(glm::radians(70.0f), mScreenWidth, mScreenHeight, 25.0f, 10000.0f);
    mProjection = CreatePerspectiveFOV(glm::radians(70.0f), mScreenWidth, mScreenHeight, 25.0f, 10000.0f);
    mMeshShader->SetMatrixUniform("uViewProj", mView * mProjection);
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
	glm::mat4 invView = glm::inverse(mView);
    glm::vec3 trans = glm::vec3(invView[3]);
	// invView.Invert();
	shader->SetVectorUniform("uCameraPos", trans);
	// Ambient light
	shader->SetVectorUniform("uAmbientLight", mAmbientLight);
	// Directional light
	shader->SetVectorUniform("uDirLight.mDirection",
		mDirLight.mDirection);
	shader->SetVectorUniform("uDirLight.mDiffuseColor",
		mDirLight.mDiffuseColor);
	shader->SetVectorUniform("uDirLight.mSpecColor",
		mDirLight.mSpecColor);
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

float Renderer::Cot(float angle){
    return 1.0f / glm::tan(angle);
}

glm::mat4 Renderer::CreatePerspectiveFOV(float fovY, float width, float height, float near, float far){
    float yScale = Cot(fovY / 2.0f);
	float xScale = yScale * height / width;
	float temp[4][4] =
	{
		{ xScale, 0.0f, 0.0f, 0.0f },
		{ 0.0f, yScale, 0.0f, 0.0f },
		{ 0.0f, 0.0f, far / (far - near), 1.0f },
		{ 0.0f, 0.0f, -near * far / (far - near), 0.0f }
	};

	glm::mat4 temp2;

	memcpy(glm::value_ptr(temp2), temp, sizeof(temp));
	return temp2;
}

glm::mat4 Renderer::CreateLookAt(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up){
    glm::vec3 zaxis = glm::normalize(target - eye);
	glm::vec3 xaxis = glm::normalize(glm::cross(up, zaxis));
	glm::vec3 yaxis = glm::normalize(glm::cross(zaxis, xaxis));
	glm::vec3 trans;

	trans.x = -glm::dot(xaxis, eye);
	trans.y = -glm::dot(yaxis, eye);
	trans.z = -glm::dot(zaxis, eye);

	float temp[4][4] =
	{
		{ xaxis.x, yaxis.x, zaxis.x, 0.0f },
		{ xaxis.y, yaxis.y, zaxis.y, 0.0f },
		{ xaxis.z, yaxis.z, zaxis.z, 0.0f },
		{ trans.x, trans.y, trans.z, 1.0f }
	};

	glm::mat4 temp2;
	memcpy(glm::value_ptr(temp2), temp, sizeof(temp));
	return temp2;
}
