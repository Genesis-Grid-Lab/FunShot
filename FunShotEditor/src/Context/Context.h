#pragma once
#include "Widget.h"

struct GuiContext : AppInterface
{ 
    GEN_INLINE virtual ~GuiContext() 
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext(); 
        glfwTerminate();
    }

    GEN_INLINE virtual void OnGuiStart() {}

    GEN_INLINE virtual void OnGuiFrame() {}

    GEN_INLINE void OnStart() override final
    { 
        // init imgui context
        IMGUI_CHECKVERSION();      
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigWindowsMoveFromTitleBarOnly = true;             
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

        ImGui_ImplOpenGL3_Init(SHADER_VERSION);
        ImGui_ImplGlfw_InitForOpenGL(GetWindowHandle(), true);

        ImFontConfig fontConfig;
        fontConfig.MergeMode = true;
        fontConfig.PixelSnapH = true;
        static const ImWchar iconRange[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };

        // regular font and icon
        io.Fonts->AddFontFromFileTTF(FONT_FILE, REGULAR_FONT_SIZE);
        io.Fonts->AddFontFromFileTTF(ICON_FONT, REGULAR_FONT_SIZE, &fontConfig, iconRange);  

        // small font and icon
        io.Fonts->AddFontFromFileTTF(FONT_FILE, SMALL_FONT_SIZE);
        io.Fonts->AddFontFromFileTTF(ICON_FONT, SMALL_FONT_SIZE, &fontConfig, iconRange);  

        // set imgui style
        ImGui::StyleColorsDark(); 

        // attach event callback                                 
        AttachCallback<SelectEvent>([this] (auto e) 
		{
			for(auto& window : m_Windows)			
				window->OnSelect(ToEntt<Entity>(e.EnttID));						
		});

        // interface start
        OnGuiStart();
    }
   
    GEN_INLINE void OnUpdate() override final 
    { 
        // Initialize ImGui for the frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();        

        // Set up the main viewport
        static auto viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowViewport(viewport->ID);  
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowPos(viewport->Pos);

        // Define main window flags
        static auto flags = ImGuiWindowFlags_NoBringToFrontOnFocus | 
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoNavFocus | 
        ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_MenuBar;

        // Set window style
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0, 0));
        ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(0, 0, 0, 1));
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0);

        // Begin the main window
        ImGui::Begin("MainWindow", NULL, flags);  
        {                   
            // Set up the main dockspace
            ImGui::DockSpace(ImGui::GetID("MainDockspace"), ImVec2(0, 0), 
            ImGuiDockNodeFlags_PassthruCentralNode);
            ImGui::PopStyleColor();
            ImGui::PopStyleVar(3);
            
            // Iterate through each window in the vector and call OnShow
            for(auto& window : m_Windows) 
            { 
                window->OnShow(this); 
            }

            // Show ImGui Demo Window for debugging purposes
            ImGui::ShowDemoWindow();

            // Interface update
            OnGuiFrame();
        }
        ImGui::End();

        if(ImGui::IsKeyPressed(ImGuiKey_ModAlt)  && ImGui::IsKeyPressed(ImGuiKey_F4))
        {
            glfwSetWindowShouldClose(GetWindowHandle(), true);
        }

        // Render ImGui draw data
        //glClear(GL_COLOR_BUFFER_BIT);   
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

  
    template<typename T, typename... Args> 
    GEN_INLINE void AttachWindow(Args&&... args) 
    {    
        GEN_STATIC_ASSERT(std::is_base_of<IWidget, T>::value);            
        auto window = std::make_unique<T>(this, std::forward<Args>(args)...);
        m_Windows.push_back(std::move(window));
    } 

    template<typename T, typename... Args> 
    GEN_INLINE auto CreateWidget(Args&&... args) 
    {    
        GEN_STATIC_ASSERT(std::is_base_of<IWidget, T>::value);            
        auto widget = std::make_unique<T>(this, std::forward<Args>(args)...);
        return widget;
    } 

private:
    std::vector<Widget> m_Windows;
};