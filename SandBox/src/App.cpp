#include <FunShot.h>

#include <glm/vec3.hpp>
#include "imgui.h"

class ExampleLayer : public FS::Layer {
public:
    ExampleLayer()
        :Layer("Example"){}

    void OnUpdate() override{    

        if(FS::Input::IsKeyPressed(FS_KEY_TAB)){
            FS_INFO("Tab key is pressed!");
        }

        glm::vec3 test = glm::vec3(0);
    }

    void OnImGuiRender() override{
        ImGui::Begin("testname");
        ImGui::Text("test");
        ImGui::End();
    }

    void OnEvent(FS::Event& event) override {
        // FS_TRACE("{0}", event);        
    }
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