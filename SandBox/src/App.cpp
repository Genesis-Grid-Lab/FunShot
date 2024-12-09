#include <FunShot.h>

#include <glm/vec3.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "imgui.h"

#include "Platform/OpenGL/OpenGLShader.h"

class ExampleLayer : public FS::Layer {
public:
    ExampleLayer()
        :Layer("Example"), m_CameraController(1280.0f / 720.0f){}

    void OnAttach() override {
        m_VertexArray = FS::VertexArray::Create();
        FS::Ref<FS::VertexBuffer> VB; 
        FS::Ref<FS::IndexBuffer> IB; 

        float vertices[3*7] = {
            -0.5f, -0.5f, 0.0f,     1.0f, 0.0f, 1.0f, 1.0f,
            0.5f, -0.5f, 0.0f,      1.0f, 0.0f, 1.0f, 1.0f,
            0.0f, 0.5f, 0.0f,       1.0f, 0.0f, 1.0f, 1.0f
        };

        VB = FS::VertexBuffer::Create(vertices, sizeof(vertices));
    
        FS::BufferLayout layout = {
            {FS::ShaderDataType::Vec3, "a_Position"},
            {FS::ShaderDataType::Vec4, "a_Color", true}
        };

        VB->SetLayout(layout);

        uint32_t indices[3] = { 0,1,2};

        IB = FS::IndexBuffer::Create(indices, 3);

        m_VertexArray->AddVertexBuffer(VB);
        m_VertexArray->SetIndexBuffer(IB);

        m_SquareVA = FS::VertexArray::Create();

        float vertices2[5*4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f,  1.0f, 0.0f,
            0.5f, 0.5f, 0.0f,   1.0f, 1.0f,
            -0.5f, 0.5f, 0.0f,  0.0f, 1.0f
        };

        VB =FS::VertexBuffer::Create(vertices2, sizeof(vertices2));

        VB->SetLayout({
            {FS::ShaderDataType::Vec3, "a_Position"},
            {FS::ShaderDataType::Vec2, "a_TexCoord"}
        });
        
        m_SquareVA->AddVertexBuffer(VB);

        uint32_t indices2[6] = { 0,1,2, 2, 3, 0};

        IB =FS::IndexBuffer::Create(indices2, 6);

        m_SquareVA->SetIndexBuffer(IB);

        shader = FS::Shader::Create("Resources/Shaders/Basic.glsl");
        shader2 = FS::Shader::Create("Resources/Shaders/Basic2.glsl");

        auto texShader = m_ShaderLibrary.Load("Resources/Shaders/Texture.glsl");

        m_Texture = FS::Texture2D::Create("Resources/board.png");

        std::dynamic_pointer_cast<FS::OpenGLShader>(texShader)->Bind();
        std::dynamic_pointer_cast<FS::OpenGLShader>(texShader)->UploadUniformInt("u_Texture", 0);

    }

    void OnUpdate(FS::Timestep ts) override{    

        m_CameraController.OnUpdate(ts);

        FS::RenderCommand::SetClearColor({0.1,0.1,0.1,1});
        FS::RenderCommand::Clear();

        FS::Renderer::BeginScene(m_CameraController.GetCamera());

        std::dynamic_pointer_cast<FS::OpenGLShader>(shader2)->Bind();
        std::dynamic_pointer_cast<FS::OpenGLShader>(shader2)->UploadUniformFloat3("u_Color", m_SquareColor);

        for(int y = 0; y < 20; y++){
            for(int x = 0; x < 20; x++){
                glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
                glm::mat4 transformS = glm::translate(glm::mat4(1.0f), pos);
                transformS = glm::scale(transformS, glm::vec3(0.1f));
                FS::Renderer::Submit(shader2, m_SquareVA, transformS);
            }
        }

        auto texShader = m_ShaderLibrary.Get("Texture");

        m_Texture->Bind();
        FS::Renderer::Submit(texShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

        //Triangle
        // FS::Renderer::Submit(shader, m_VertexArray);

        FS::Renderer::EndScene();
    }

    void OnImGuiRender() override{
        ImGui::Begin("Settings");
        ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
        ImGui::End();
    }

    void OnEvent(FS::Event& event) override {
        m_CameraController.OnEvent(event);
    }

private:
    FS::ShaderLibrary m_ShaderLibrary;
    FS::Ref<FS::Shader> shader;
    FS::Ref<FS::VertexArray> m_VertexArray;

    FS::Ref<FS::Shader> shader2;
    FS::Ref<FS::VertexArray> m_SquareVA;

    FS::Ref<FS::Texture2D> m_Texture;

    FS::OrthographicCameraController m_CameraController;

    glm::vec3 m_SquareColor = {0.2f,0.3f,0.8f};
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