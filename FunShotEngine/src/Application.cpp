#include "fspch.h"
#include "Core/Application.h"
#include "Application.h"
#include "Auxiliaries/ECS.h"

// #include "Engine/Renderer/Renderer.h"

// #include <GLFW/glfw3.h> // temp

namespace FS {

    Application* Application::s_Instance = nullptr;

    Application::Application(){
        // FS_PROFILE_FUNCTION();

        FS_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        WindowProps props;

        m_Window = CreateScope<Window>(props);
        m_Assets = CreateScope<AssetRegistry>();
        m_Renderer = CreateScope<Renderer>();
        m_Buffer3D = CreateScope<Framebuffer>(GetScreenWidth(), GetScreenHeight());
        m_Buffer2D = CreateScope<Framebuffer>(GetScreenWidth(), GetScreenHeight());

        tex = LoadTexture("Resources/Textures/Game/1_club.png");

        // Renderer::Init();

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);

    }
    Application::~Application(){
        // FS_PROFILE_FUNCTION();
        // Renderer::Shutdown();
    }

    void Application::PushLayer(Layer* layer){
        // FS_PROFILE_FUNCTION();
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer){
        // FS_PROFILE_FUNCTION();
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::Render3D(Timestep& timestep){

        m_Renderer->GetBuffer(Renderer::Buffer::e_3D)->Bind();
        {
            // FS_PROFILE_SCOPE("LayerStack OnUpdate");
            for(Layer* layer : m_LayerStack)
                layer->OnUpdate(timestep);
        }
        {
            ClearBackground(BLACK);
            BeginMode3D(m_Renderer->m_GlobalCam);
            EnttView<Entity, ModelComponent>([this] (auto entity, auto& comp)
            {
                auto& transform = entity.template Get<TransformComponent>().Transforms;
                auto& model = m_Assets->Get<ModelAsset>(comp.Model);
                // DrawModelEx(model.Data, transform.translation, { 0.0f, 1.0f, 0.0f }, 0.0f, transform.scale, WHITE);
                DrawModel(model.Data, transform.translation, transform.scale.x, WHITE);
            });

            DrawGrid(10, 1.0);
            rlDisableBackfaceCulling();
            rlDisableDepthMask();
            EnttView<Entity, SkyboxComponent>([this] (auto entity, auto& comp)
            {
                auto& skybox = m_Assets->Get<SkyboxAsset>(comp.Skybox);
                DrawModel(skybox.Data, {0}, 10.0f, WHITE);
                
            });
            rlEnableBackfaceCulling();
            rlEnableDepthMask();
            EndMode3D();        

            DrawFPS(10, 10);
        }
        m_Renderer->GetBuffer(Renderer::Buffer::e_3D)->Unbind();

        m_Buffer3D->Bind();
        {
            // FS_PROFILE_SCOPE("LayerStack OnUpdate");
            for(Layer* layer : m_LayerStack)
                layer->OnUpdate(timestep);
        }
        
        ClearBackground(BLACK);        

        EnttView<Entity, CameraComponent>([this] (auto entity, auto& comp)
        {
            auto& transform = entity.template Get<TransformComponent>().Transforms;
            auto& cam = comp.Camera;
            cam.target = Vector3{4.0f, 1.0f, 4.0f};
            cam.up = Vector3{0.0f, 1.0f, 0.0f};
            cam.fovy = 45.0f;
            cam.position = transform.translation;
            cam.projection = CAMERA_PERSPECTIVE;
            
            BeginMode3D(cam);
        });

        EnttView<Entity, ModelComponent>([this] (auto entity, auto& comp)
        {
            auto& transform = entity.template Get<TransformComponent>().Transforms;
            auto& model = m_Assets->Get<ModelAsset>(comp.Model);
            // DrawModelEx(model.Data, transform.translation, { 0.0f, 1.0f, 0.0f }, 0.0f, transform.scale, WHITE);
            DrawModel(model.Data, transform.translation, transform.scale.x, WHITE);
        });

        DrawGrid(10, 1.0);
        rlDisableBackfaceCulling();
        rlDisableDepthMask();
        EnttView<Entity, SkyboxComponent>([this] (auto entity, auto& comp)
        {
            auto& skybox = m_Assets->Get<SkyboxAsset>(comp.Skybox);
            DrawModel(skybox.Data, {0}, 10.0f, WHITE);
            
        });
        rlEnableBackfaceCulling();
        rlEnableDepthMask();
        EndMode3D(); 

        m_Buffer3D->Unbind();
    }

    void Application::Render2D(Timestep& timestep){

         m_Renderer->GetBuffer(Renderer::Buffer::e_2D)->Bind();
        {
            // FS_PROFILE_SCOPE("LayerStack OnUpdate");
            for(Layer* layer : m_LayerStack)
                layer->OnUpdate(timestep);
        }
        {            
            ClearBackground(BLACK);
            
            EnttView<Entity, SpriteComponent>([this] (auto entity, auto& comp)
            {
                auto& transform = entity.template Get<TransformComponent>().Transforms;
                auto& texture = m_Assets->Get<TextureAsset>(comp.Texture);
                DrawTextureV(texture.Data, {transform.translation.x, transform.translation.y}, WHITE);
            });

                             
            DrawFPS(10, 10);            
        }
        m_Renderer->GetBuffer(Renderer::Buffer::e_2D)->Unbind();

        m_Buffer2D->Bind();
        {
            // FS_PROFILE_SCOPE("LayerStack OnUpdate");
            for(Layer* layer : m_LayerStack)
                layer->OnUpdate(timestep);
        }
        {            
            ClearBackground(BLACK);
            
            EnttView<Entity, SpriteComponent>([this] (auto entity, auto& comp)
            {
                auto& transform = entity.template Get<TransformComponent>().Transforms;
                auto& texture = m_Assets->Get<TextureAsset>(comp.Texture);
                DrawTextureV(texture.Data, {transform.translation.x, transform.translation.y}, WHITE);                
            });

            // DrawTextureV(tex, {0, 0}, WHITE);

        }        
        m_Buffer2D->Unbind();
    }

    void Application::RenderPlay()
    {
        m_Renderer->GetBuffer(Renderer::Buffer::e_Play)->Bind();
        {
            if(!m_Switch2D){
                DrawTextureRec(m_Buffer3D->GetTexture().texture, 
                { 0, 0, (float)m_Buffer3D->GetTexture().texture.width, (float)-m_Buffer3D->GetTexture().texture.height }, 
                { 0, 0 }, WHITE);
            }
            else{
                DrawTextureRec(m_Buffer2D->GetTexture().texture, 
                { 0, 0, (float)m_Buffer2D->GetTexture().texture.width, (float)-m_Buffer2D->GetTexture().texture.height }, 
                { 0, 0 }, WHITE);                        
            }
        }
        m_Renderer->GetBuffer(Renderer::Buffer::e_Play)->Unbind();
    }

    void Application::Run()
    {
        // FS_PROFILE_FUNCTION();
        while(!WindowShouldClose() && m_Running){            
            // FS_PROFILE_SCOPE("RunLoop");
            m_Dispatcher.PollEvents();
            float time = (float)GetTime();
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;
            BeginDrawing();
            
            if(!m_Minimized){
                {
                    // if(m_ViewportFocused)
                    m_Renderer->Update();                           

                    
                    ClearBackground(WHITE);
                    
                    Render3D(timestep);
                    Render2D(timestep);        
                    RenderPlay();
                    
                }
            }

            //// GAME/////
            if(!m_Switch2D){
                DrawTextureRec(m_Buffer3D->GetTexture().texture, 
                { 0, 0, (float)m_Buffer3D->GetTexture().texture.width, (float)-m_Buffer3D->GetTexture().texture.height }, 
                { 0, 0 }, WHITE);
            }
            else{
                DrawTextureRec(m_Buffer2D->GetTexture().texture, 
                { 0, 0, (float)m_Buffer2D->GetTexture().texture.width, (float)-m_Buffer2D->GetTexture().texture.height }, 
                { 0, 0 }, WHITE);                        
            }
            m_ImGuiLayer->Begin();
            {
                // FS_PROFILE_SCOPE("LayerStack OnImGuiRender");
                for(Layer* layer : m_LayerStack)
                    layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();

            // FS_CORE_INFO("{0}", m_Switch2D);
            EndDrawing();
            // m_Window->OnUpdate();
                
        }
    }
}