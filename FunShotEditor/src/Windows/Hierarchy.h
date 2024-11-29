#pragma once
#include "Context/Context.h"
#include "MenuList.h"

struct HierarchyWindow : IWidget
{	
	GEN_INLINE HierarchyWindow(GuiContext* context): IWidget(context)
	{
		m_Window.push_back(context->CreateWidget<MenuListWindow>());
	}

    GEN_INLINE void OnShow(GuiContext* context) override
	{
        if(ImGui::Begin(ICON_FA_CUBES "\tHierarchy")) 
		{
			context->EnttView<Entity, InfoComponent>([&] (auto entity, auto& info) 
			{	
				// check if current entity is selected
				bool isSelected = (m_Selected.ID() == entity.ID());

				// makes each selectable unique
				ImGui::PushID((int32_t)entity.ID());

				// compute selectable label
				std::string label = ICON_FA_CUBE "\t" + info.Name;

				// special label with icons
				if(entity.template Has<DirectLightComponent>())
					label = ICON_FA_SUN "\t" + info.Name;
				if(entity.template Has<CameraComponent>())
					label = ICON_FA_VIDEO "\t" + info.Name;
				if(entity.template Has<RigidBodyComponent>())
					label = ICON_FA_PERSON "\t" + info.Name;
				if(entity.template Has<SkyboxComponent>())
					label = ICON_FA_CLOUD_SUN_RAIN "\t" + info.Name;

				// show entity selectable
				if(ImGui::Selectable(label.c_str(), &isSelected))
				{
					context->PostEvent<SelectEvent>(entity);
				}
				if(ImGui::IsItemHovered() && ImGui::GetIO().MouseClicked[1])
				{
					ImGui::OpenPopup(label.c_str());
					
				}								

				if (ImGui::BeginPopup(label.c_str()))
	    		{
					ImGui::Text(label.c_str());
					if(ImGui::BeginMenu("Add Component"))
					{
						if(ImGui::MenuItem(ICON_FA_SUN "Add Light"))
						{
							entity.template Attach<DirectLightComponent>();
						}
						if(ImGui::MenuItem(ICON_FA_VIDEO "Add Camera"))
						{
							entity.template Attach<CameraComponent>();
						}
						ImGui::EndMenu();
					}
					if(ImGui::Button("Delete"))
					{
						entity.Destroy();
					}
       		    	ImGui::EndPopup();
        		} 

				
				// w are required to pop
				ImGui::PopID();
			});
        }
        ImGui::End();
    }

	GEN_INLINE void OnSelect(Entity entity) override 
	{
		m_Selected = entity;						
	}
	
private:
	Entity m_Selected;
	std::vector<Widget> m_Window;
};