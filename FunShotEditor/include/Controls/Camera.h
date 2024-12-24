#pragma once
#include "IControl.h"

namespace FS {

    class CameraControl : public IControl<CameraComponent>
    {
    public:
        inline CameraControl(EditorLayer* context): IControl(context)
        {
            SetTitle(ICON_FA_VIDEO "\tCamera");
        }

        inline void OnBody(EditorLayer* context, Entity& entity)
        {
            auto& data = entity.template Get<CameraComponent>().Camera;
            InputVec3("Position", &data.position);
            InputVec3("Target", &data.target);
            InputFloat("FOV", &data.fovy);
            // InputVec3("test", &data.test);
            // InputVec3("test2", &data.test2);
        }

        inline void OnMenu(EditorLayer* context, Entity& entity)
        {
            if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset"))
            {
                entity.template Get<CameraComponent>() = {};
            }
            if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove"))
            {
                entity.template Detach<CameraComponent>();
            }
        }
    };
}