#include "Sandbox2D.h"
#include "imgui.h"
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
    :Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f){
}

void Sandbox2D::OnAttach()
{
    m_Texture = FS::Texture2D::Create("Resources/Textures/board.png");
}

void Sandbox2D::OnDetach(){
}

void Sandbox2D::OnUpdate(FS::Timestep ts){
    m_CameraController.OnUpdate(ts);

    FS::RenderCommand::SetClearColor({0.1,0.1,0.1,1});
    FS::RenderCommand::Clear();

    FS::Renderer2D::BeginScene(m_CameraController.GetCamera());

    FS::Renderer2D::DrawQuad({-1.0f, 0.0f}, {0.8f, 0.8f}, {0.8f, 0.2f, 0.3f, 1.0f} );
    FS::Renderer2D::DrawQuad({0.5f, -0.5f}, {0.5f, 0.65f}, m_SquareColor );
    FS::Renderer2D::DrawQuad({0.0f,0.0f, -0.1f}, {10.0f,10.0f}, m_Texture);

    FS::Renderer2D::EndScene();
}

void Sandbox2D::OnImGuiRender(){
    ImGui::Begin("Settings");
    ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
    ImGui::End();
}

void Sandbox2D::OnEvent(FS::Event &event){
    m_CameraController.OnEvent(event);
}