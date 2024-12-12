#include "fspch.h"
#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FS {
    OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
        :m_ProjectionMatrix(glm::ortho(left, right, bottom, top, -1.0f, 1.0f)), m_ViewMatrix(1.0f){
        FS_PROFILE_FUNCTION();
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    void OrthographicCamera::SetProjection(float left, float right, float bottom, float top){
        FS_PROFILE_FUNCTION();
        m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }

    void OrthographicCamera::RecalculateViewMatrix(){
        FS_PROFILE_FUNCTION();
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, m_Position);
        transform = glm::rotate(transform, glm::radians(m_Rotation), glm::vec3(0,0,1));

        m_ViewMatrix = glm::inverse(transform);
        m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
    }
}