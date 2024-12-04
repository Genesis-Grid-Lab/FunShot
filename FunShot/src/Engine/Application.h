#pragma once

#include "Window.h"
#include "Engine/LayerStack.h"
#include "Engine/Events/Event.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/ImGui/ImGuiLayer.h"

#include "Engine/Renderer/Shader.h"
#include "Engine/Renderer/Buffer.h"

namespace FS {

    class FS_API Application{
    public:
        Application();
        virtual ~Application();

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window;}
        inline ImGuiLayer& GetImGuiLayer() { return *m_ImGuiLayer;}

        inline static Application& Get(){ return *s_Instance;}
    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        unsigned int m_VertexArray;
        std::unique_ptr<Shader> shader;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
    private:
        static Application* s_Instance;
    };

    // to be defined in client
    Application* CreateApplication();
}