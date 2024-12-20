#include "fspch.h"
#include "OrthographicCameraController.h"

#include "Engine/Core/Input.h"
#include "Engine/Core/KeyCode.h"


namespace FS
{
    OrthographicCameraController::OrthographicCameraController(float aspecRatio, bool rotation)
        :m_AspectRatio(aspecRatio),  m_Bounds({ -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel }), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation){
    }

    void OrthographicCameraController::OnUpdate(Timestep ts){
        FS_PROFILE_FUNCTION();
        if(Input::IsKeyPressed(FS_KEY_A))
            m_CameraPosition.x -= m_CameraPositionSpeed * ts;
        else if(Input::IsKeyPressed(FS_KEY_D))
            m_CameraPosition.x += m_CameraPositionSpeed * ts;
        if(Input::IsKeyPressed(FS_KEY_W))
            m_CameraPosition.y += m_CameraPositionSpeed * ts;
        else if(Input::IsKeyPressed(FS_KEY_S))
            m_CameraPosition.y -= m_CameraPositionSpeed * ts;

        if(m_Rotation)
        {   if(Input::IsKeyPressed(FS_KEY_Q))
                m_CameraRotation += m_CameraRotationSpeed * ts;
            if(Input::IsKeyPressed(FS_KEY_E))
                m_CameraRotation -= m_CameraRotationSpeed * ts;

            m_Camera.SetRotation(m_Rotation);
        }

        m_Camera.SetPosition(m_CameraPosition);
        m_CameraPositionSpeed = m_ZoomLevel;
    }

    void OrthographicCameraController::OnEvent(Event &e){
        FS_PROFILE_FUNCTION();
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
    }

    void OrthographicCameraController::Resize(float width, float height){
        m_AspectRatio = width / height;
        CalculateView();
    }

    void OrthographicCameraController::CalculateView(){
        m_Bounds = { -m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
        m_Camera.SetProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent &e)
    {
        FS_PROFILE_FUNCTION();
        m_ZoomLevel -= e.GetYOffset() * 0.5f;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        CalculateView();
        return false;
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent &e){
        Resize((float)e.GetWidth() , (float)e.GetHeight());
        return false;
    }

} // namespace FS
