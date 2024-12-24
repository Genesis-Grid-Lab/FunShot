#include "ImGui/ImGuiLayer.h"

#include <imgui_impl_raylib.h>

#include "Core/Application.h"

#define FONT_FILE "Resources/Fonts/Roboto-Medium.ttf"
#define ICON_FONT "Resources/Fonts/fa-solid-900.ttf"
#define REGULAR_FONT_SIZE 17
#define SMALL_FONT_SIZE 15


namespace FS {

    ImGuiLayer::ImGuiLayer()
        : Layer("ImGuiLayer"){}

    ImGuiLayer::~ImGuiLayer() {}

    void ImGuiLayer::OnAttach(){
        // FS_PROFILE_FUNCTION();

        // Setup Dear ImGui context
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsLight();

        // Setup Platform/Renderer backends
        ImGui_ImplRaylib_Init();
        
        // Load Fonts
        // // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
        // // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
        // // - If the file cannot be loaded, the function will return a nullptr. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
        // // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
        // // - Use '#define IMGUI_ENABLE_FREETYPE' in your imconfig file to use Freetype for higher quality font rendering.
        // // - Read 'docs/FONTS.md' for more instructions and details.
        // // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
        // io.Fonts->AddFontDefault();
        // //io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\segoeui.ttf", 18.0f);
        // //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
        // //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
        // //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
        // ImFont* font = io.Fonts->AddFontFromFileTTF("Resources/Fonts/driusstraight.ttf", 18.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
        // IM_ASSERT(font != nullptr);

        // required to be called to cache the font texture with raylib
        // ImGui_ImplRaylib_BuildFontAtlas();

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
        ImGui_ImplRaylib_BuildFontAtlas();
        if (!std::filesystem::exists("imgui.ini"))
		{
			ImGui::LoadIniSettingsFromDisk("Resources/ImGui/default.ini");
		}

        // if the linked ImGui has docking, enable it.
        // this will only be true if you use the docking branch of ImGui.
    #ifdef IMGUI_HAS_DOCK
        ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    #endif
    ImGui::GetIO().ConfigWindowsMoveFromTitleBarOnly = true;
    }

    void ImGuiLayer::OnDetach(){
    //     FS_PROFILE_FUNCTION();

        ImGui_ImplRaylib_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnImGuiRender(){

    }

    void ImGuiLayer::Begin(){
        // FS_PROFILE_FUNCTION();
        
        ImGui_ImplRaylib_ProcessEvents();

        // Start the Dear ImGui frame
        ImGui_ImplRaylib_NewFrame();
        ImGui::NewFrame();
    }

    void ImGuiLayer::End(){
        // FS_PROFILE_FUNCTION();
    
         ImGui::Render();
         ImGui_ImplRaylib_RenderDrawData(ImGui::GetDrawData());
    }
}