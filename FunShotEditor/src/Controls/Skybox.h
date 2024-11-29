#pragma once
#include "IControl.h"

struct SkyboxControl : IControl<SkyboxComponent>
{    
    GEN_INLINE SkyboxControl(GuiContext* context): IControl(context)
	{
		SetTitle(ICON_FA_CLOUD_SUN_RAIN "\tSkybox");
	}

    GEN_INLINE void OnBody(GuiContext* context, Entity& entity) 
	{
       /* auto& data = entity.template Get<CameraComponent>().Camera;
        InputFloat("Near", &data.NearPlane);
        InputFloat("Far", &data.FarPlane);
        InputFloat("FOV", &data.FOV);  */  
    }

    GEN_INLINE void OnMenu(GuiContext* context, Entity& entity) 
	{
        if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset")) 
		{
            entity.template Get<SkyboxComponent>() = {};
        }        
    }
};