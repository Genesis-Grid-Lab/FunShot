#pragma once
#include <FunShot.h>

#include "ParticleSystem.h"

class Sandbox2D : public FS::Layer {
public:
    Sandbox2D();
    ~Sandbox2D() = default;
    void OnAttach() override;
    void OnDetach() override;
    void OnUpdate(FS::Timestep ts) override;
    void OnImGuiRender() override;
    void OnEvent(FS::Event& event) override;
private:
    FS::OrthographicCameraController m_CameraController;

    FS::Ref<FS::Shader> m_Shader;
    FS::Ref<FS::VertexArray> m_SquareVA;
    glm::vec4 m_SquareColor = {0.2f,0.3f,0.8f, 1.0f};
    FS::Ref<FS::VertexArray> m_VertexArray;


    FS::Ref<FS::Texture2D> m_Texture;
};