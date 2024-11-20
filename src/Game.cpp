#include "Game.h"
#include "ECS.h"
#include "GLFW/glfw3.h"

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

    EnttView<Entity, Camera3DComponent>([this](auto entity, auto&comp){
        auto& transform = entity.template Get<Transform3DComponent>().Transform;
        int state = glfwGetKey(mWindow->Handle(), GLFW_KEY_A);
        if(state == GLFW_PRESS){
            transform.Translate.x += 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_D);
        if(state == GLFW_PRESS){
            transform.Translate.x -= 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_S);
        if(state == GLFW_PRESS){
            transform.Translate.y += 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_W);
        if(state == GLFW_PRESS){
            transform.Translate.y -= 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_SPACE);
        if(state == GLFW_PRESS){
            transform.Translate.z -= 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_LEFT_SHIFT);
        if(state == GLFW_PRESS){
            transform.Translate.z += 1;
        }
    });

    EnttView<Entity, SpriteComponent>([this](auto entity, auto&comp){
        auto& transform = entity.template Get<Transform2DComponent>().Transform;
        int state = glfwGetKey(mWindow->Handle(), GLFW_KEY_LEFT);
        if(state == GLFW_PRESS){
            transform.Translate.x -= 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_RIGHT);
        if(state == GLFW_PRESS){
            transform.Translate.x += 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_DOWN);
        if(state == GLFW_PRESS){
            transform.Translate.y -= 1;
        }

        state = glfwGetKey(mWindow->Handle(), GLFW_KEY_UP);
        if(state == GLFW_PRESS){
            transform.Translate.y += 1;
        }
    });
}

void Game::UpdateGame(){

}

void Game::GenerateOutput(){
    mRenderer->Draw();
}

bool Game::LoadData(){
    auto cam = CreateEntt<Entity>();
    cam.Attach<Camera3DComponent>();
    auto& tc1 = cam.Attach<Transform3DComponent>().Transform;
    tc1.Translate = glm::vec3(0);

    auto sprite = CreateEntt<Entity>();
    auto& sp = sprite.Attach<SpriteComponent>();
    sp.Texture.Load("Resources/Assets/Plane.png");
    auto &tc2 = sprite.Attach<Transform2DComponent>().Transform;
    tc2.Translate = glm::vec2(200);
    tc2.Scale = glm::vec2(0.5);

    auto mesh = CreateEntt<Entity>();
    mesh.Attach<MeshComponent>().mMesh.Load("Resources/Assets/Sphere.gpmesh",mRenderer);
    auto &tc = mesh.Attach<Transform3DComponent>().Transform;
    tc.Translate = glm::vec3(1, 1, 20);
    tc.Scale = glm::vec3(1);

    return true;
}

void Game::UnloadData(){

}
