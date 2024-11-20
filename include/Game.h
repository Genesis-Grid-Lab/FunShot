#pragma once
#include "Window.h"
#include "Renderer.h"

class Game{
public:
    Game();
    ~Game();
    //init the game
    bool Init();
    //run
    void Run();
    //shutdown
    void Shutdown();
private:
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    bool LoadData();
    void UnloadData();

public:
    template<typename Entt, typename... Args>
    inline Entt CreateEntt(Args&&... args){
        return std::move(Entt(&mRegistry, std::forward<Args>(args)...));
    }

    template<typename Entt>
    inline Entt ToEntt(EntityID entity){
        return std::move(Entt(&mRegistry, entity));
    }

    template<typename Entt, typename Comp, typename Task>
    inline void EnttView(Task&& task){
        mRegistry.view<Comp>().each([this, &task]
        (auto entity, auto& comp)
        {
            task(std::move(Entt(&mRegistry, entity)), comp);
        });
    }

private:
    EntityRegistry mRegistry;
    Window* mWindow;
    Renderer* mRenderer;
    bool mIsRunning;

    class Shader* mSpriteShader;
    class VertexArray* mSpriteVerts;    
};