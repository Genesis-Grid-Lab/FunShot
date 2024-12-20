#pragma once
#include "Engine/Renderer/Camera.h"
#include "Engine/Core/Timestep.h"

#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Events/MouseEvent.h"

namespace FS {

    struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return Right - Left; }
		float GetHeight() { return Top - Bottom; }
	};

    class OrthographicCameraController {
    public:
        OrthographicCameraController(float aspecRatio, bool rotation = false);

        void OnUpdate(Timestep ts);
        void OnEvent(Event& e);

        void Resize(float width, float height);

        OrthographicCamera& GetCamera() { return m_Camera;}
        const OrthographicCamera& GetCamera() const { return m_Camera;}
        const OrthographicCameraBounds& GetBounds() const { return m_Bounds; }

        void SetZoomLevel(float level){ m_ZoomLevel = level; CalculateView();}
        float GEtZoomLevel() { return m_ZoomLevel;}
    private:
        void CalculateView();

        bool OnMouseScrolled(MouseScrolledEvent& e);
        bool OnWindowResized(WindowResizeEvent& e);   
    private:
        float m_AspectRatio;
        float m_ZoomLevel = 1.0f;
        OrthographicCamera m_Camera;
        OrthographicCameraBounds m_Bounds;

        bool m_Rotation;
        glm::vec3 m_CameraPosition = {0.0f, 0.0f, 0.0f};
        float m_CameraPositionSpeed = 5;
        float m_CameraRotation = 0.0f;
        float m_CameraRotationSpeed = 160.0f;
    };
}