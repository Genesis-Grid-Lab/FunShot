#pragma once
#include "IControl.h"

namespace FS {

    class ModelAssetControl : public IControl<ModelAsset>
    {
    public:  
        inline ModelAssetControl(EditorLayer* context): IControl(context)
        {
            SetTitle(ICON_FA_LOCATION_ARROW "\tModelAsset");
        }

        inline void OnBodyAsset(EditorLayer* context, AssetID& asset) 
        {
            auto& image = Application::Get().m_Assets->Get<ModelAsset>(asset);
            
            // auto& tex = image.Data.materials[0].maps[0].texture;

            // std::string width = std::to_string(tex.width);

            // InputText("Name", image.Name.c_str());
            // FS_INFO("{0}", image.Name);
            ImGui::Text(image.Name.c_str());
        }

        inline void OnMenuAsset(EditorLayer* context) 
        {
            if (ImGui::Selectable(ICON_FA_RECYCLE "\tReset")) 
            {
                // entity.template Get<TransformComponent>() = {};
            }
            if (ImGui::Selectable(ICON_FA_RECYCLE "\tRemove")) 
            {
                // entity.template Detach<TransformComponent>();
            }     
        }
    };
}