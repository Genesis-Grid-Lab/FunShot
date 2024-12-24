#pragma once

#include "Editor/EditorLayer.h"

namespace FS {

    class MenuListWindow : public IWidget
    {
    public:
        inline MenuListWindow(EditorLayer* context) : IWidget(context)
        {

        }

        inline void OnShow(EditorLayer* context) override
        {
            ImGui::OpenPopup("my_select_popup");
            ImGui::SameLine();

            if (ImGui::BeginPopup("my_select_popup"))
            {
                ImGui::EndPopup();
            } 
        }
    };
}