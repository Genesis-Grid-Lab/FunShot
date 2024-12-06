#include <FunShot.h>

#include <glm/vec3.hpp>
#include "imgui.h"

using namespace FS;

class ExampleLayer : public FS::Layer {
public:
    ExampleLayer()
        :Layer("Example"){}

    void OnAttach() override {
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

    void OnUpdate() override{    

        RenderCommand::SetClearColor(glm::vec4(0.1,0.1,0.1,1));
        RenderCommand::Clear();

        Renderer::BeginScene();

        shader2->Bind();
        Renderer::Submit(m_SquareVA);

        shader->Bind();
        Renderer::Submit(m_VertexArray);

        Renderer::EndScene();
    }

    void OnImGuiRender() override{
        ImGui::Begin("testname");
        ImGui::Text("test2");
        ImGui::End();
    }

    void OnEvent(FS::Event& event) override {
        // FS_TRACE("{0}", event);        
    }

private:
    std::shared_ptr<Shader> shader;
    std::shared_ptr<VertexArray> m_VertexArray;

    std::shared_ptr<Shader> shader2;
    std::shared_ptr<VertexArray> m_SquareVA;
};

class SandBox : public FS::Application{
public:
    SandBox(){
        PushLayer(new ExampleLayer());
    }
    ~SandBox() {}
};

FS::Application* FS::CreateApplication(){
    return new SandBox();
}