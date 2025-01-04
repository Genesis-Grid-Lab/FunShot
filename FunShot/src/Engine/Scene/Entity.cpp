#include "fspch.h"
#include "Entity.h"


namespace FS {

    Entity::Entity(entt::entity handle, Scene* scene)
        :m_EntityHandle(handle), m_Scene(scene){}
}