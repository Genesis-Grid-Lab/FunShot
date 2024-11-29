#pragma once
#include "Assets.h"

namespace Gen
{   
    // direct light component
    struct DirectLightComponent 
    {
        GEN_INLINE DirectLightComponent(const DirectLightComponent&) = default;
        GEN_INLINE DirectLightComponent() = default; 
        DirectLight Light;
    };

    // point light component
    struct PointLightComponent 
    {
        GEN_INLINE PointLightComponent(const PointLightComponent&) = default;
        GEN_INLINE PointLightComponent() = default; 
        PointLight Light;
    };

    // point light component
    struct SpotLightComponent 
    {
        GEN_INLINE SpotLightComponent(const SpotLightComponent&) = default;
        GEN_INLINE SpotLightComponent() = default; 
        SpotLight Light;
    };

    // transform component
    struct TransformComponent 
    {
        GEN_INLINE TransformComponent(const TransformComponent&) = default;
        GEN_INLINE TransformComponent() = default; 
        Transform3D Transform;
    }; 
    
    // rigid body component
    struct RigidBodyComponent 
    {
        GEN_INLINE RigidBodyComponent(const RigidBodyComponent&) = default;
        GEN_INLINE RigidBodyComponent() = default; 
        RigidBody3D RigidBody;
    }; 

    // collider component
    struct ColliderComponent 
    {
        GEN_INLINE ColliderComponent(const ColliderComponent&) = default;
        GEN_INLINE ColliderComponent() = default; 
        Collider3D Collider;
    }; 

    // camera component
    struct CameraComponent 
    {
        GEN_INLINE CameraComponent(const CameraComponent&) = default;
        GEN_INLINE CameraComponent() = default; 
        Camera3D Camera; 
    }; 

    // camera 2d component
    struct Camera2DComponent
    {
        GEN_INLINE Camera2DComponent(const Camera2DComponent&) = default;
        GEN_INLINE Camera2DComponent() = default;
        Camera2D Camera;
    };

    // skybox component
    struct SkyboxComponent 
    {
        GEN_INLINE SkyboxComponent(const SkyboxComponent&) = default;
        GEN_INLINE SkyboxComponent() = default; 
        AssetID Skybox = EMPTY_ASSET;
    };    

    // script component
    struct ScriptComponent 
    {
        GEN_INLINE ScriptComponent(const ScriptComponent&) = default;
        GEN_INLINE ScriptComponent() = default; 
        AssetID Script = EMPTY_ASSET;
        LuaScript Instance;
    }; 

    // model component
    struct ModelComponent 
    { 
        GEN_INLINE ModelComponent(const ModelComponent&) = default;
        GEN_INLINE ModelComponent() = default; 
        AssetID Material = EMPTY_ASSET; 
        AssetID Model = EMPTY_ASSET; 
    };

    // common component
    struct InfoComponent 
    { 
        GEN_INLINE InfoComponent(const InfoComponent&) = default;
        GEN_INLINE InfoComponent() = default; 
        AssetID Parent = EMPTY_ASSET;
        std::string Name = "Entity"; 
        AssetID UID = RandomU64();
    };

    // base entity
    struct Entity 
    {
        GEN_INLINE Entity(EntityRegistry* registry, EntityID entity): 
            m_Registry(registry), m_EnttID(entity) 
        {}
        
        GEN_INLINE Entity(EntityRegistry* registry): 
        m_Registry(registry) 
        {
            m_EnttID = m_Registry->create();		 			
        }

        GEN_INLINE virtual ~Entity() = default;
        GEN_INLINE Entity() = default;		

        GEN_INLINE operator EntityID () 
        { 
            return m_EnttID; 
        }

        GEN_INLINE operator bool()  
        { 
            return m_Registry != nullptr && 
            m_Registry->valid(m_EnttID);
        }       

        GEN_INLINE EntityID ID() 
        { 
            return m_EnttID; 
        }
        
        // ++

        template<typename T, typename... Args>
        GEN_INLINE T& Attach(Args&&... args) 
        {
            return m_Registry->get_or_emplace<T>
            (m_EnttID, std::forward<Args>(args)...);
        }

        template<typename T>
        GEN_INLINE void Detach() 
        { 
            m_Registry->remove<T>(m_EnttID); 
        }

        GEN_INLINE void Destroy() 
        {
            if(m_Registry) 
            { 
                m_Registry->destroy(m_EnttID); 
            }
        }

        template<typename T>
        GEN_INLINE bool Has()  
        { 
            return m_Registry != nullptr && 
            m_Registry->all_of<T>(m_EnttID); 
        }

        template<typename T>
        GEN_INLINE T& Get() 
        { 
            return m_Registry->get<T>(m_EnttID); 
        }

    protected:
        EntityRegistry* m_Registry = nullptr;
        EntityID m_EnttID = NENTT;
    };
}