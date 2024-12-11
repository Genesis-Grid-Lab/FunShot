#include "fspch.h"
#include "OrthographicCameraController.h"

#include "Engine/Core/Input.h"
#include "Engine/Core/KeyCode.h"


namespace FS
{
    OrthographicCameraController::OrthographicCameraController(float aspecRatio, bool rotation)
        :m_AspecRatio(aspecRatio),m_Camera(-m_AspecRatio * m_ZoomLevel, m_AspecRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel), m_Rotation(rotation){
    }

    void OrthographicCameraController::OnUpdate(Timestep ts){

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

        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<MouseScrolledEvent>(BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled));
        dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(OrthographicCameraController::OnWindowResized));
    }

    bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent &e){
        
        m_ZoomLevel -= e.GetYOffset() * 0.5f;
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
        m_Camera.SetProjection(-m_AspecRatio * m_ZoomLevel, m_AspecRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

    bool OrthographicCameraController::OnWindowResized(WindowResizeEvent &e){
        m_AspecRatio = (float)e.GetWidth() / (float)e.GetHeight();
        m_Camera.SetProjection(-m_AspecRatio * m_ZoomLevel, m_AspecRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        return false;
    }

} // namespace FS
