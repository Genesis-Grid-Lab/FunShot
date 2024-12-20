#include "Sandbox2D.h"
#include "imgui.h"
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
    :Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f){
}

void Sandbox2D::OnAttach()
{
    FS_PROFILE_FUNCTION();
    m_Texture = FS::Texture2D::Create("Resources/Textures/Checkerboard.png");

}

void Sandbox2D::OnDetach(){
    FS_PROFILE_FUNCTION();
}  

void Sandbox2D::OnUpdate(FS::Timestep ts){

    FS_PROFILE_FUNCTION();
    {
        FS_PROFILE_SCOPE("CameraController::OnUpdate");
        m_CameraController.OnUpdate(ts);
    }

    FS::Renderer2D::ResetStats();
    {
        FS_PROFILE_SCOPE("Renderer prep");
        FS::RenderCommand::SetClearColor({0.1,0.1,0.1,1});
        FS::RenderCommand::Clear();
    }

    {
        static float rotation = 0.0f;
        rotation += ts * 20.0f;
        FS_PROFILE_SCOPE("Renderer draw");
        FS::Renderer2D::BeginScene(m_CameraController.GetCamera());

        FS::Renderer2D::DrawRotatedQuad({1.0f, 0.0f}, {0.8f, 0.8f}, glm::radians(45.0f), {0.8f, 0.2f, 0.3f, 1.0f} );
        FS::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f} );
        FS::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.65f}, m_SquareColor );
        FS::Renderer2D::DrawQuad({0.0f,0.0f, -0.1f}, {20.0f,20.0f}, m_Texture, 10);
        FS::Renderer2D::DrawRotatedQuad({-0.5f,-0.5f}, {1.0f,1.0f}, glm::radians(rotation), m_Texture, 20);

        FS::Renderer2D::EndScene();

        FS::Renderer2D::BeginScene(m_CameraController.GetCamera());
        for(float y = -5.0f; y < 5.0f; y += 0.5f){
            for(float x = -5.0f; x < 5.0f; x += 0.5f){
                glm::vec4 color = {(x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 1.0f};
                FS::Renderer2D::DrawQuad({x,y}, {0.45f, 0.45f}, color );
            }
        }
        FS::Renderer2D::EndScene();
    }

}

void Sandbox2D::OnImGuiRender(){
    FS_PROFILE_FUNCTION();
    ImGui::Begin("Settings");

    auto stats = FS::Renderer2D::GetStats();
    ImGui::Text("Renderer2D Stats:");
    ImGui::Text("Draw Calls: %d", stats.DrawCalls);
    ImGui::Text("Quads: %d", stats.QuadCount);
    ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
    ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

    ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(FS::Event &event){
    m_CameraController.OnEvent(event);
}
