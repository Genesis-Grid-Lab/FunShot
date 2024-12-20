#include "fspch.h"
#include "Application.h"
#include "Input.h"

#include "Engine/Renderer/Renderer.h"

#include <GLFW/glfw3.h> // temp

namespace FS {

    Application* Application::s_Instance = nullptr;

    Application::Application(const std::string& name){
        FS_PROFILE_FUNCTION();

        FS_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = Scope<Window>(Window::Create(WindowProps(name)));
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

        Renderer::Init();

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);

    }
    Application::~Application(){
        FS_PROFILE_FUNCTION();
        Renderer::Shutdown();
    }

    void Application::PushLayer(Layer* layer){
        FS_PROFILE_FUNCTION();
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer){
        FS_PROFILE_FUNCTION();
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e){
        FS_PROFILE_FUNCTION();
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(Application::OnWindowResize));

        // FS_CORE_TRACE("{0}", e);

        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();){
            (*--it)->OnEvent(e);
            if(e.m_Handled)
                break;
        }
    }

    void Application::Run(){
        FS_PROFILE_FUNCTION();
        while(m_Running){            
            FS_PROFILE_SCOPE("RunLoop");
            float time = (float)glfwGetTime();
            Timestep timestep = time - m_LastFrameTime;
            m_LastFrameTime = time;

            if(!m_Minimized){
                {
                    FS_PROFILE_SCOPE("LayerStack OnUpdate");
                    for(Layer* layer : m_LayerStack)
                        layer->OnUpdate(timestep);
                }
            }
            m_ImGuiLayer->Begin();
            {
                FS_PROFILE_SCOPE("LayerStack OnImGuiRender");
                for(Layer* layer : m_LayerStack)
                    layer->OnImGuiRender();
            }
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
                
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e){
        m_Running = false;

        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent &e){
        FS_PROFILE_FUNCTION();
        if(e.GetWidth() == 0 || e.GetHeight() == 0){

            m_Minimized = true;
            return false;
        }

        m_Minimized = false;
        Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

        return false;
    }
}