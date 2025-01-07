#include "Test.h"
#include "imgui.h"
#include <glm/gtc/type_ptr.hpp>
#include "Engine/Scene/SceneSerializer.h"

Test::Test()
    :Layer("Test"){
        m_ActiveScene = CreateRef<Scene>();
   
    SceneSerializer serializer(m_ActiveScene);  
    serializer.Deserialize("Resources/Scenes/CubeExample.FunShot");
}

void Test::OnAttach()
{
    FS_PROFILE_FUNCTION();
    
}

void Test::OnDetach(){
    FS_PROFILE_FUNCTION();
}  

void Test::OnUpdate(FS::Timestep ts){
    m_ActiveScene->OnViewportResize(1600, 900);

    RenderCommand::SetClearColor({0.1,0.1,0.1,1});
    RenderCommand::Clear();
    m_ActiveScene->OnUpdateRuntime(ts);

}

void Test::OnImGuiRender(){
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

void Test::OnEvent(FS::Event &event){
    
}
