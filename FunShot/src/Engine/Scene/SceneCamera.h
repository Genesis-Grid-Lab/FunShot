#pragma once

#include "Engine/Renderer/Camera.h"

namespace FS {

    class SceneCamera : public Camera{
    public:
        enum class ProjectionType { Perspective = 0, Orthographic = 1};
    public:
        SceneCamera();
        virtual ~SceneCamera();
        
        void SetOrthographic(float size, float nearClip, float farClip);
        void SetPerspective(float verticalFOV, float nearClip, float farClip);

        void SetViewportSize(uint32_t width, uint32_t height);

        float GetOrthoSize() const { return m_OrthographicSize;}
        void SetOrthoSize(float size) { m_OrthographicSize = size; RecalculateProjection();}
        float GetOrthoNearClip() const { return m_OrthographicNear;}
        void SetOrthoNearClip(float nearClip) { m_OrthographicNear = nearClip; RecalculateProjection();}
        float GetOrthoFarClip() const { return m_OrthographicFar;}
        void SetOrthoFarClip(float farClip) { m_OrthographicFar = farClip; RecalculateProjection();}

        float GetPerspectiveVerticalFOV() const { return m_PerspectiveFOV;}
        void SetPerspectiveVerticalFOV(float fov) { m_PerspectiveFOV = fov; RecalculateProjection();}
        float GetPerspectiveNearClip() const { return m_PerspectiveNear;}
        void SetPerspectiveNearClip(float nearClip) { m_PerspectiveNear = nearClip; RecalculateProjection();}
        float GetPerspectiveFarClip() const { return m_PerspectiveFar;}
        void SetPerspectiveFarClip(float farClip) { m_PerspectiveFar = farClip; RecalculateProjection();}

        ProjectionType GetProjectionType() const { return m_ProjectionType;}
        void SetProjectionType(ProjectionType type) { m_ProjectionType = type; RecalculateProjection();}
    private:
        void RecalculateProjection();
    private:
        ProjectionType m_ProjectionType = ProjectionType::Orthographic;
        float m_OrthographicSize    = 10.0f;
        float m_OrthographicNear    = -1.0f;
        float m_OrthographicFar     =  1.0f;

        float m_PerspectiveFOV      = glm::radians(45.0f);
        float m_PerspectiveNear     = 0.01f;
        float m_PerspectiveFar      =  1000.0f;

        float m_AspectRation = 0.0f;
    };
}