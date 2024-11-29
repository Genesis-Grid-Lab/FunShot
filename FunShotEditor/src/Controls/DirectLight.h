#pragma once
#include "IControl.h"

struct DirectLightControl : IControl<DirectLightComponent>
{    
    GEN_INLINE DirectLightControl(GuiContext* context): IControl(context)
	{
		SetTitle(ICON_FA_SUN "\tDirect Light");
	}

    GEN_INLINE void OnBody(GuiContext* context, Entity& entity) 
	{
        auto& data = entity.template Get<DirectLightComponent>().Light;
        InputFloat("Intensity", &data.Intensity);
        InputColor("Radiance", &data.Radiance.x);
        InputFloat("Bias", &data.ShadowBias);    
    }

    GEN_INLINE void OnMenu(GuiContext* context, Entity& entity) 
	{
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset")) 
		{
            entity.template Get<DirectLightComponent>() = {};
        }        
    }
};