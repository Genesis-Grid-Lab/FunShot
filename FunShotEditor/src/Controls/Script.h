#pragma once
#include "IControl.h"

struct ScriptControl : IControl<ScriptComponent>
{    
    GEN_INLINE ScriptControl(GuiContext* context): IControl(context)
	{
		SetTitle(ICON_FA_PENCIL "\tScript");
	}

    GEN_INLINE void OnBody(GuiContext* context, Entity& entity) 
	{
        auto& data = entity.template Get<ScriptComponent>();
        ImGui::Text("Script UUID: (%d)", data.Script);
    }

    GEN_INLINE void OnMenu(GuiContext* context, Entity& entity) 
	{
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset")) 
		{
            //entity.template Get<ScriptComponent>() = {};
        }        
    }
};