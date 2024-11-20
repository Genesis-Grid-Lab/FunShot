#include "Game.h"
#include "ECS.h"
#include "ResourceManager.h"
#include "Vertex.h"

Game::Game()
{
    mIsRunning = true;
    mSpriteShader = nullptr;
    mWindow = nullptr;
    mRenderer = nullptr;
}

Game::~Game(){
    Shutdown();
    FN_INFO("destroy game class");
}

void Game::Shutdown(){    
    UnloadData();
    if(mRenderer){
        mRenderer->Shutdown();
    }
    delete mWindow;
}

bool Game::Init(){
    mWindow = new Window("FunShot", 1280, 720);

    if(!mWindow->Init()){

        FN_FATAL("failed to init mWindow\n");
        return false;
    }

    // create the renderer
    mRenderer = new Renderer(this);
    if(!mRenderer->Init(1280, 720)){
        FN_FATAL("Failed to ini mRenderer\n");
        delete mRenderer;
        mRenderer = nullptr;
        return false;
    }

    LoadData();

    return true;
}

void Game::Run(){

    while(mWindow->PollEvents() & mIsRunning){
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

void Game::ProcessInput(){
    int state = glfwGetKey(mWindow->Handle(), GLFW_KEY_ESCAPE);
    if(state == GLFW_PRESS){
        mIsRunning = false;
    }
}

void Game::UpdateGame(){

}

void Game::GenerateOutput(){
    mRenderer->Draw();
    
}

bool Game::LoadData(){
    Mesh meh = ResourceManager::LoadMesh("Resources/Assets/Cube.gpmesh",mRenderer, "Cube");


    auto sprite = CreateEntt<Entity>();
    auto& sp = sprite.Attach<SpriteComponent>();
    sp.Texture = ResourceManager::LoadTexture("Resources/Image/container.jpg", true, "texture");
    auto &tc2 = sprite.Attach<Transform2DComponent>().Transform;
    tc2.Translate = glm::vec2(100);
    tc2.Scale = glm::vec2(0.5);

    auto mesh = CreateEntt<Entity>();
    mesh.Attach<MeshComponent>().mMesh = meh;
    auto &tc = mesh.Attach<Transform3DComponent>().Transform;
    tc.Translate = glm::vec3(1.0f, 1.0f, 1.0f);
    
    return true;
}

void Game::UnloadData(){

}