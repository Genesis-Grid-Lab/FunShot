#pragma once

#include "Engine/Scene/Scene.h"
#include "Engine/Core/Core.h"
#include "Engine/Scene/Entity.h"

namespace FS {

    class SceneHierarachyPanel{
    public:
        SceneHierarachyPanel() = default;
        SceneHierarachyPanel(const Ref<Scene>& context);

        void SetContext(const Ref<Scene>& context);

        void OnImGuiRender();
    private:
        void DrawEntityNode(Entity entity);
    private:
        Ref<Scene> m_Context;
        Entity m_SelectionContext;
    };
}