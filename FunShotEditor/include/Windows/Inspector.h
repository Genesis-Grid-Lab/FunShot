#pragma once
// #include "Controls/Camera.h"
#include "Controls/EnttInfo.h"
#include "Controls/Transform.h"
#include "Controls/ModelAssetControl.h"
// #include "Controls/DirectLight.h"
// #include "Controls/Skybox.h"
// #include "Controls/Model.h"
// #include "Controls/RigidBody.h"
// #include "Controls/Script.h"
// #include "Controls/Collider.h"
// #include "Controls/PointLight.h"
// #include "Controls/SpotLight.h"
// #include "Controls/Camera2D.h"

namespace FS {

    struct InspectorWindow : public IWidget
    {	
        inline InspectorWindow(EditorLayer* context): IWidget(context)
        {
            m_Widgets.push_back(context->CreateWidget<InfoControl>());		
            m_Widgets.push_back(context->CreateWidget<TransformControl>());	
            // m_Widgets.push_back(context->CreateWidget<CameraControl>());
            // m_Widgets.push_back(context->CreateWidget<Camera2DControl>());
            // m_Widgets.push_back(context->CreateWidget<DirectLightControl>());
            // m_Widgets.push_back(context->CreateWidget<SkyboxControl>());
            // m_Widgets.push_back(context->CreateWidget<ModelControl>());
            // m_Widgets.push_back(context->CreateWidget<RigidBodyControl>());
            // m_Widgets.push_back(context->CreateWidget<ScriptControl>());
            // m_Widgets.push_back(context->CreateWidget<ColliderControl>());
            // m_Widgets.push_back(context->CreateWidget<PointLightControl>());
            // m_Widgets.push_back(context->CreateWidget<SpotLightControl>());

            m_Widgets.push_back(context->CreateWidget<ModelAssetControl>());	
        }

        inline void OnShow(EditorLayer* context) override
        {
            if(ImGui::Begin(ICON_FA_CIRCLE_INFO "\tInspector")) 
            {
                for(auto& widget : m_Widgets)			
                    widget->OnShow(context);
                
            }
            ImGui::End();
        }

        inline void OnShowAsset(EditorLayer* context) override
        {
            if(ImGui::Begin(ICON_FA_CIRCLE_INFO "\tAsset Inspector")) 
            {
                for(auto& widget : m_Widgets)			
                    widget->OnShowAsset(context);
                
            }
            ImGui::End();
        }


        inline void OnSelect(Entity entity) override 
        {
            for(auto& widget : m_Widgets)			
                widget->OnSelect(entity);            					
        }

        inline void OnSelect(AssetID asset) override 
        {
            for(auto& widget : m_Widgets)			
                widget->OnSelect(asset);            					
        }	
        
    private:
        std::vector<Widget> m_Widgets;
    };
}