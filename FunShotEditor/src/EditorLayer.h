#pragma once
#include <FunShot.h>
#include "Panels/SceneHierarchyPanel.h"

namespace FS {

    class EditorLayer : public Layer {
    public:
        EditorLayer();
        ~EditorLayer() = default;
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;
        void OnEvent(Event& event) override;
    private:
        OrthographicCameraController m_CameraController;

        Ref<Shader> m_Shader;
        Ref<VertexArray> m_SquareVA;
        glm::vec4 m_SquareColor = {0.2f,0.3f,0.8f, 1.0f};
        Ref<VertexArray> m_VertexArray;

        Ref<Framebuffer> m_Framebuffer;

        Ref<Scene> m_ActiveScene;
        Entity m_SquareEntity;

        Entity m_CameraEntity;
        Entity m_SecondCamera;

        bool m_PrimaryCamera = true;
        
        glm::vec2 m_ViewportSize;
        bool m_ViewportFocused = false, m_ViewportHovered = false;

        Ref<Texture2D> m_Texture;

        SceneHierarachyPanel m_SceneHierarachyPanel;
    };
}