#include "fspch.h"
#include "Application.h"
#include "Input.h"

#include <glad/glad.h>

namespace FS {

    Application* Application::s_Instance = nullptr;

    Application::Application(){
        FS_CORE_ASSERT(!s_Instance, "Application already exists!");
        s_Instance = this;

        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();
        PushOverlay(m_ImGuiLayer);

        m_VertexArray.reset(VertexArray::Create());
        std::shared_ptr<VertexBuffer> VB; 
        std::shared_ptr<IndexBuffer> IB; 

        float vertices[3*7] = {
            -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 1.0f, 1.0f,
            0.0f, 0.5f, 0.0f,       1.0f, 0.0f, 1.0f, 1.0f
        };

        VB.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
    
        BufferLayout layout = {
            {ShaderDataType::Vec3, "a_Position"},
            {ShaderDataType::Vec4, "a_Color", true}
        };

        VB->SetLayout(layout);

        uint32_t indices[3] = { 0,1,2};

        IB.reset(IndexBuffer::Create(indices, 3));

        m_VertexArray->AddVertexBuffer(VB);
        m_VertexArray->SetIndexBuffer(IB);

        m_SquareVA.reset(VertexArray::Create());

        float vertices2[3*4] = {
            -0.75f, -0.75f, 0.0f,
            0.75f, -0.75f, 0.0f, 
            0.75f, 0.75f, 0.0f,
            -0.75f, 0.75f, 0.0f
        };

        VB.reset(VertexBuffer::Create(vertices2, sizeof(vertices2)));

        VB->SetLayout({
            {ShaderDataType::Vec3, "a_Position"}
        });
        
        m_SquareVA->AddVertexBuffer(VB);

        uint32_t indices2[6] = { 0,1,2, 2, 3, 0};

        IB.reset(IndexBuffer::Create(indices2, 6));

        m_SquareVA->SetIndexBuffer(IB);

        std::string vertexSrc = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Pos;
            layout(location = 1) in vec4 a_Color;

            out vec3 v_Pos;
            out vec4 v_Color;
            
            void main()
            {
                v_Pos = a_Pos;
                v_Color = a_Color;
                gl_Position = vec4(a_Pos, 1.0);
            }
        )";

        std::string fragSrc = R"(
            #version 330 core

            layout(location = 0) out vec4 color;
            in vec3 v_Pos;
            in vec4 v_Color;
            
            void main()
            {
                color = v_Color;
            }
        )";

        std::string vertexSrc2 = R"(
            #version 330 core

            layout(location = 0) in vec3 a_Pos;

            out vec3 v_Pos;
            
            void main()
            {
                v_Pos = a_Pos;
                gl_Position = vec4(a_Pos, 1.0);
            }
        )";

        std::string fragSrc2 = R"(
            #version 330 core

            layout(location = 0) out vec4 color;
            in vec3 v_Pos;
            
            void main()
            {
                color = vec4(0,1,0,1);
            }
        )";

        shader.reset(new Shader(vertexSrc, fragSrc));
        shader2.reset(new Shader(vertexSrc2, fragSrc2));

    }
    Application::~Application(){}

    void Application::PushLayer(Layer* layer){
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer* layer){
        m_LayerStack.PushOverlay(layer);
        layer->OnAttach();
    }

    void Application::OnEvent(Event& e){

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

        // FS_CORE_TRACE("{0}", e);

        for(auto it = m_LayerStack.end(); it != m_LayerStack.begin();){
            (*--it)->OnEvent(e);
            if(e.m_Handled)
                break;
        }
    }

    void Application::Run(){

        while(m_Running){
            glClearColor(0.1,0.1,0.1,1);
            glClear(GL_COLOR_BUFFER_BIT);

            shader2->Bind();
            m_SquareVA->Bind();
            glDrawElements(GL_TRIANGLES, m_SquareVA->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

            shader->Bind();
            m_VertexArray->Bind();
            glDrawElements(GL_TRIANGLES, m_VertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

            for(Layer* layer : m_LayerStack)
                layer->OnUpdate();

            m_ImGuiLayer->Begin();
            for(Layer* layer : m_LayerStack)
                layer->OnImGuiRender();
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

    bool Application::OnWindowClose(WindowCloseEvent& e){
        m_Running = false;

        return true;
    }
}