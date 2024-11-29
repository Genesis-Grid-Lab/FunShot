#pragma once
#include "../../Common/Core.h"

namespace Gen
{
    struct MaterialUniform 
    {
        GEN_INLINE void Initialize(uint32_t shader)
        {
            UseRoughnessMap = glGetUniformLocation(shader, "u_material.UseRoughnessMap");
            UseOcclusionMap = glGetUniformLocation(shader, "u_material.UseOcclusionMap");
            UseEmissiveMap = glGetUniformLocation(shader, "u_material.UseEmissiveMap");
            UseMetallicMap = glGetUniformLocation(shader, "u_material.UseMetallicMap");
            UseAlbedoMap = glGetUniformLocation(shader, "u_material.UseAlbedoMap");
            UseNormalMap = glGetUniformLocation(shader, "u_material.UseNormalMap");

            RoughnessMap = glGetUniformLocation(shader, "u_material.RoughnessMap");
            OcclusionMap = glGetUniformLocation(shader, "u_material.OcclusionMap");
            EmissiveMap = glGetUniformLocation(shader, "u_material.EmissiveMap");
            MetallicMap = glGetUniformLocation(shader, "u_material.MetallicMap");
            AlbedoMap = glGetUniformLocation(shader, "u_material.AlbedoMap");
            NormalMap = glGetUniformLocation(shader, "u_material.NormalMap");

            Roughness = glGetUniformLocation(shader, "u_material.Roughness");
            Occlusion = glGetUniformLocation(shader, "u_material.Occlusion");
            Emissive = glGetUniformLocation(shader, "u_material.Emissive");
            Metallic = glGetUniformLocation(shader, "u_material.Metallic");
            Albedo = glGetUniformLocation(shader, "u_material.Albedo");
        }

        uint32_t UseRoughnessMap = 0u;
        uint32_t UseOcclusionMap = 0u;
        uint32_t UseEmissiveMap = 0u;
        uint32_t UseMetallicMap = 0u;
        uint32_t UseAlbedoMap = 0u;
        uint32_t UseNormalMap = 0u;
        // --
        uint32_t RoughnessMap = 0u; 
        uint32_t OcclusionMap = 0u;  
        uint32_t EmissiveMap = 0u;  
        uint32_t MetallicMap = 0u;  
        uint32_t AlbedoMap = 0u;    
        uint32_t NormalMap = 0u;    
        // --
        uint32_t Roughness = 0u;
        uint32_t Occlusion = 0u;
        uint32_t Emissive = 0u;
        uint32_t Metallic = 0u;
        uint32_t Albedo = 0u;
    };

    // pbr material
    struct Material 
    {
        GEN_INLINE Material(const Material&) = default;
        GEN_INLINE Material() = default;

        // material maps
        uint32_t RoughnessMap = 0u;
        uint32_t OcclusionMap = 0u;
        uint32_t EmissiveMap = 0u;
        uint32_t MetallicMap = 0u;
        uint32_t AlbedoMap = 0u;
        uint32_t NormalMap = 0u;

        // material props
        glm::vec3 Emissive = glm::vec3(0.0f);
        glm::vec3 Albedo = glm::vec3(1.0f);
        float Occlusion = 1.0f;
        float Roughness = 0.5f;
        float Metallic = 0.6f;
    };
      
    // point light
    struct PointLight 
    {
        GEN_INLINE PointLight(const PointLight&) = default;
        GEN_INLINE PointLight() = default; 
        
        glm::vec3 Radiance = glm::vec3(1.0f);
        float Intensity = 10.0f;
    };

    // point light
    struct SpotLight 
    {
        GEN_INLINE SpotLight(const SpotLight&) = default;
        GEN_INLINE SpotLight() = default; 
        
        glm::vec3 Radiance = glm::vec3(1.0f);
        float Intensity = 3.5f;
		float FallOff = 60.5f;
        float CutOff = 20.0f;
    };

    // directional light
    struct DirectLight 
    {
        GEN_INLINE DirectLight(const DirectLight&) = default;
        GEN_INLINE DirectLight() = default; 
        
        glm::vec3 Radiance = glm::vec3(1.0f);
        float ShadowBias = 0.05f;
        float Intensity = 10.0f;
    };

    // transform
    struct Transform3D
    {
        GEN_INLINE Transform3D(const Transform3D&) = default;
        GEN_INLINE Transform3D() = default; 

        GEN_INLINE glm::mat4 Matrix() const 
        {
            return (glm::translate(glm::mat4(1.0f), Translate) * 
            glm::toMat4(glm::quat(glm::radians(Rotation))) * 
            glm::scale(glm::mat4(1.0f), Scale));
        }

        glm::vec3 Translate = glm::vec3(0.0f);  
        glm::vec3 Rotation = glm::vec3(0.0f);    
        glm::vec3 Scale = glm::vec3(1.0f);
    };

    // camera
    struct Camera3D
    {
        GEN_INLINE Camera3D(const Camera3D&) = default;
        GEN_INLINE Camera3D() = default;

        GEN_INLINE glm::mat4 Frustum(const Transform3D& transform, float ratio) const 
        {
            return Projection(ratio) * View(transform);
        }

        GEN_INLINE glm::mat4 View(const Transform3D& transform) const 
        {
            return glm::lookAt(transform.Translate, (transform.Translate + 
            glm::vec3(0.0f, 0.0f, -1.0f)), glm::vec3(0.0f, 1.0f, 0.0f)) * 
            glm::toMat4(glm::quat(glm::radians(transform.Rotation)));
        }

        GEN_INLINE glm::mat4 Projection(float ratio) const 
        {
            return glm::perspective(FOV, ratio, NearPlane, FarPlane);
        }

        float NearPlane = 0.3000f;
        float FarPlane = 1000.0f;
        float FOV = 45.0f;
    };

    struct Camera2D
    {
        GEN_INLINE Camera2D(const Camera2D&) = default;
        GEN_INLINE Camera2D() = default;

        GEN_INLINE glm::mat4 Frustum(const Transform3D& transform, float ratio) const 
        {
            return Projection(ratio) * View(transform);
        }

        GEN_INLINE glm::mat4 View(const Transform3D& transform) const 
        {
            return glm::lookAt(transform.Translate, (transform.Translate + 
            glm::vec3(0.0f, 0.0f, -1.0f)), glm::vec3(0.0f, 1.0f, 0.0f)) * 
            glm::toMat4(glm::quat(glm::radians(transform.Rotation)));
        }

        GEN_INLINE glm::mat4 Projection(float ratio) const 
        {
            return glm::perspective(FOV, ratio, NearPlane, FarPlane);
        }

        float NearPlane = 0.100f;
        float FarPlane = 100.0f;
        float FOV = 1.0f;
    };

    // skybox data
    struct Skybox
    {
        GEN_INLINE Skybox(const Skybox&) = default;
        GEN_INLINE Skybox() = default; 
        uint32_t PrefilMap = 0u;            
        uint32_t IrradMap = 0u;        
        uint32_t CubeMap = 0u;        
        uint32_t BrdfMap = 0u;
    };
}