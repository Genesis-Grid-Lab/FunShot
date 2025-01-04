#pragma once

#include "Engine/Renderer/Camera.h"

namespace FS {

    class SceneCamera : public Camera{
    public:
        SceneCamera();
        virtual ~SceneCamera();
        
        void SetOrthographic(float size, float nearClip, float farClip);
        void SetViewportSize(uint32_t width, uint32_t height);

        float GetOrthoSize() const { return m_OrthographicSize;}
        void SetOrthoSize(float size) { m_OrthographicSize = size; RecalculateProjection();}
    private:
        void RecalculateProjection();
    private:
        float m_OrthographicSize    = 10.0f;
        float m_OrthographicNear    = -1.0f;
        float m_OrthographicFar     =  1.0f;

        float m_AspectRation = 0.0f;
    };
}