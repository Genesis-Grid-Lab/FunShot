#pragma once

#include "Core/Window.h"
#include "Core/LayerStack.h"
#include "ImGui/ImGuiLayer.h"

#include "Auxiliaries/Assets.h"
#include "Event.h"
#include "Renderer/Renderer.h"

#include "Core/Timestep.h"

namespace FS {

    class  Application{
    public:
        Application();
        virtual ~Application();

        void Run();

        void Close() { m_Running = false;}

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window;}
        inline ImGuiLayer& GetImGuiLayer() { return *m_ImGuiLayer;}

        inline static Application& Get(){ return *s_Instance;}

        inline Renderer& GetRenderer() { return *m_Renderer;}

    public:
        // create entity
        template <typename Entt, typename... Args>
        inline Entt CreateEntt(Args&&... args)
        {
            // GEN_STATIC_ASSERT(std::is_base_of<Entity, Entt>::value);
            return std::move(Entt(&m_Scene, std::forward<Args>(args)...));
        }

        // convert id to entity
        template<typename Entt>
        inline Entt ToEntt(EntityID entity)
        {
            // GEN_STATIC_ASSERT(std::is_base_of<Entity, Entt>::value);
            return std::move(Entt(&m_Scene, entity));
        }

        // loop through entities
        template<typename Entt, typename Comp, typename Task>
        inline void EnttView(Task&& task)
        {
            // GEN_STATIC_ASSERT(std::is_base_of<Entity, Entt>::value);
            m_Scene.view<Comp>().each([this, &task]
            (auto entity, auto& comp)
            {
                task(std::move(Entt(&m_Scene, entity)), comp);
            });
        }

        // loop through entities
        template<typename Task>
        inline void AssetView(Task&& task)
        {
            m_Assets->View([&] (auto asset) { task(asset); });
        }

        // attach event callback
        template <typename Event, typename Callback>
        inline void AttachCallback(Callback&& callback)
        {
            m_Dispatcher.AttachCallback<Event>(std::move(callback), m_LayerID);
        }

        // post event
        template <typename Event, typename... Args>
        inline void PostEvent(Args&&...args)
        {
            m_Dispatcher.PostEvent<Event>(std::forward<Args>(args)...);
        }

        // post task event
        template <typename Task>
        inline void PostTask(Task&& task)
        {
            m_Dispatcher.PostTask(std::move(task));
        }

        // detach callback
        template <typename Event>
        inline void DetachCallback()
        {
            m_Dispatcher.DetachCallback<Event>(m_LayerID);
        }
        //temp
        Scope<AssetRegistry> m_Assets;
        EventDispatcher m_Dispatcher;
        uint32_t m_LayerID;
        bool m_Switch2D = true;

    private:
        void Render3D(Timestep& timestep);     
        void Render2D(Timestep& timestep);
        void RenderPlay();
    private:
        Scope<Window> m_Window;
        Scope<Renderer> m_Renderer;
        ImGuiLayer* m_ImGuiLayer;
        Scope<Framebuffer> m_Buffer3D;     
        Scope<Framebuffer> m_Buffer2D;  
        Texture2D tex;  
        bool m_Running = true;
        bool m_Minimized = false;
        LayerStack m_LayerStack;
        float m_LastFrameTime = 0.0f;
        EntityRegistry m_Scene;
    private:
        static Application* s_Instance;
    };

    // to be defined in client
    Application* CreateApplication();
}