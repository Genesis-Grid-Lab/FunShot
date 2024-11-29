#pragma once
#include "IControl.h"

struct RigidBodyControl : IControl<RigidBodyComponent>
{    
    GEN_INLINE RigidBodyControl(GuiContext* context): IControl(context)
	{
		SetTitle(ICON_FA_PERSON "\tRigidBody");
	}

    GEN_INLINE void OnBody(GuiContext* context, Entity& entity) 
	{
        auto& data = entity.template Get<RigidBodyComponent>().RigidBody;
        ImGui::Text("Density: (%f)", data.Density);
        //ImGui::Text("Dynamic: (%d)", data.)
    }

    GEN_INLINE void OnMenu(GuiContext* context, Entity& entity) 
	{
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset")) 
		{
            entity.template Get<RigidBodyComponent>() = {};
        }        
    }
};