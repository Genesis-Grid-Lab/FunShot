#include "Windows/Inspector.h"
#include "Windows/Hierarchy.h"
#include "Windows/Resource.h"
#include "Windows/Viewport.h"
#include "Windows/MenuBar.h"

struct Editor : GuiContext
{
    GEN_INLINE void OnGuiStart() 
    {
       PostEvent<SelectEvent>((EntityID)4);

       AttachWindow<HierarchyWindow>();
       AttachWindow<InspectorWindow>();
       AttachWindow<ResourceWindow>();
       AttachWindow<ViewportWindow>();
       AttachWindow<MenuBarWindow>();
    }

    GEN_INLINE void OnGuiFrame()
    {
       /*if(ImGui::GetIO().MouseClicked[1])
		{
			/*for(auto& window : m_Window)
			    window->OnShow(context);
					
       		ImGui::OpenPopup("my_select_popup");
        	ImGui::SameLine();
        						
		}

		if (ImGui::BeginPopup("my_select_popup"))
        {
            ImGui::EndPopup();
        }*/ 
    }
};

int32_t main(int32_t argc, char** argv) 
{
    auto app = new Application();
    app->AttachLayer<Editor>();
    app->RunContext(false);
    GEN_DELETE(app);
    return 0;
}