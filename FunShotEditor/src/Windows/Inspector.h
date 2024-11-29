#pragma once
#include "Controls/Camera.h"
#include "Controls/EnttInfo.h"
#include "Controls/Transform.h"
#include "Controls/DirectLight.h"
#include "Controls/Skybox.h"
#include "Controls/Model.h"
#include "Controls/RigidBody.h"
#include "Controls/Script.h"

struct InspectorWindow : IWidget
{	
	GEN_INLINE InspectorWindow(GuiContext* context): IWidget(context)
	{
		m_Widgets.push_back(context->CreateWidget<InfoControl>());		
		m_Widgets.push_back(context->CreateWidget<TransformControl>());		
		m_Widgets.push_back(context->CreateWidget<CameraControl>());		
		m_Widgets.push_back(context->CreateWidget<DirectLightControl>());
		m_Widgets.push_back(context->CreateWidget<SkyboxControl>());
		m_Widgets.push_back(context->CreateWidget<ModelControl>());
		m_Widgets.push_back(context->CreateWidget<RigidBodyControl>());
		m_Widgets.push_back(context->CreateWidget<ScriptControl>());
	}

    GEN_INLINE void OnShow(GuiContext* context) override
	{
        if(ImGui::Begin(ICON_FA_CIRCLE_INFO "\tInspector")) 
		{
			for(auto& widget : m_Widgets)			
				widget->OnShow(context);
        }
        ImGui::End();
    }

	GEN_INLINE void OnSelect(Entity entity) override 
	{
		for(auto& widget : m_Widgets)			
			widget->OnSelect(entity);						
	}
	
private:
	std::vector<Widget> m_Widgets;
};