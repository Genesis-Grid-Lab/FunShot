#pragma once
#include "Context/Context.h"

struct MenuListWindow : IWidget
{
    GEN_INLINE MenuListWindow(GuiContext* context) : IWidget(context)
    {

    }

    GEN_INLINE void OnShow(GuiContext* context) override
    {
        ImGui::OpenPopup("my_select_popup");
    	ImGui::SameLine();

        if (ImGui::BeginPopup("my_select_popup"))
        {
            ImGui::EndPopup();
        } 
    }
};