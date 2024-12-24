#include "EditorLayer.h"
#include "Core/Application.h"
#include "Windows/Hierarchy.h"
#include "Windows/Viewport.h"
#include "Windows/ViewportPlay.h"
#include "Windows/Viewport2D.h"
#include "Windows/MenuBar.h"
#include "Windows/Resource.h"
#include "Windows/Inspector.h"

namespace FS {

    EditorLayer::EditorLayer()
        :Layer("EditorLayer"){
    }

    void EditorLayer::OnAttach()
    {

        Application::Get().AttachCallback<SelectEvent>([this] (auto e){
            for(auto& window : m_Windows)
                window->OnSelect(Application::Get().ToEntt<Entity>(e.EnttID));

        });

        Application::Get().AttachCallback<ASelectEvent>([this] (auto e){
            for(auto& window : m_Windows)
                window->OnSelect(Application::Get().m_Assets->Get<Asset>(e.m_Asset).UID);

        });

        OnGuiStart();
        // auto asset = Application::Get().m_Assets->AddModel(RandomU64(), "first");
        // auto asset2 = Application::Get().m_Assets->AddModel(RandomU64(), "second");
        // auto robotAsset = Application::Get().m_Assets->AddModel(RandomU64(), "Resources/Models/boy.obj");
        // auto sphereAsset = Application::Get().m_Assets->AddModel(RandomU64(), "Resources/Models/sphere.obj");
        // // auto skyboxAsset = Application::Get().m_Assets->AddSkybox(RandomU64(), "Resources/Textures/HDRs/Sky.hdr", 2048, true);
        // auto skyboxAsset = Application::Get().m_Assets->AddSkybox(RandomU64(), "Resources/Textures/HDRs/Sky.png");
        // // auto skyboxAsset = Application::Get().m_Assets->AddSkybox(RandomU64(), "Resources/Textures/HDRs/skybox.png");
        // // auto skyboxAsset = Application::Get().m_Assets->AddSkybox(RandomU64(), "Resources/Textures/HDRs/dresden_square_2k.hdr", 2048, true);

        // image = LoadImage("Resources/Textures/HDRs/skybox.png");      // Load cubicmap image (RAM)
        // cubicmap = LoadTextureFromImage(image);       // Convert image to texture to display (VRAM)

        // // mesh = GenMeshCubicmap(image, Vector3{ 10.0f, 10.0f, 10.0f });
        // mesh = GenMeshCube(1.0f, 1.0f, 1.0f);
        // model = LoadModelFromMesh(mesh);

        // // NOTE: By default each cube is mapped to one part of texture atlas
        // Texture2D texture = LoadTexture("Resources/Textures/HDRs/Sky.png");    // Load map texture
        // model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = texture;

        // auto cam = Application::Get().CreateEntt<Entity>();
        // cam.Attach<InfoComponent>().Name = "Cam";
        // cam.Attach<CameraComponent>();
        // auto& camTs = cam.Attach<TransformComponent>().Transforms;
        // camTs.translation = Vector3{0.0f};

        // auto entity = Application::Get().CreateEntt<Entity>();
        // entity.Attach<InfoComponent>().Name = "Skybox";
        // entity.Attach<SkyboxComponent>().Skybox = skyboxAsset->UID;

        // auto ball = Application::Get().CreateEntt<Entity>();
        // ball.Attach<InfoComponent>().Name = "Ball";
        // auto& ballTS = ball.Attach<TransformComponent>().Transforms;
        // ball.Attach<ModelComponent>().Model = sphereAsset->UID;
        // ballTS.translation.x = 0.0f;
        // ballTS.scale = Vector3{1};

        // auto boy = Application::Get().CreateEntt<Entity>();
        // boy.Attach<InfoComponent>().Name = "boy";
        // auto& boyTS = boy.Attach<TransformComponent>().Transforms;
        // boy.Attach<ModelComponent>().Model = robotAsset->UID;
        // boyTS.translation = Vector3{0.0f, 0.0f, 0.0f};
        // boyTS.scale = Vector3{0.1f};
    }

    void EditorLayer::OnDetach(){
    }  

    void EditorLayer::OnUpdate(Timestep ts){
        
    }

    void EditorLayer::OnImGuiRender(){
        // FS_PROFILE_FUNCTION();

        // Set up the main viewport
        static auto viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowPos(viewport->Pos);

        static auto flags = ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
        ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoNavFocus |
        ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_MenuBar;

        // if you want windows to dock to the viewport, call this.
    #ifdef IMGUI_HAS_DOCK
            ImGui::DockSpaceOverViewport(0,  NULL, ImGuiDockNodeFlags_PassthruCentralNode); // set ImGuiDockNodeFlags_PassthruCentralNode so that we can see the raylib contents behind the dockspace
    #endif
        {
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
                    window->OnShowAsset(this);
                }

                // m_ViewportFocused = ImGui::IsWindowFocused();

                // Interface update
                OnGuiFrame();
            }
            ImGui::End();
            }
        

    }

    void EditorLayer::OnGuiStart(){

        AttachWindow<HierarchyWindow>();        
        AttachWindow<ViewportWindow>();        
        AttachWindow<ViewportPlayWindow>();
        AttachWindow<Viewport2DWindow>();
        AttachWindow<MenuBarWindow>();
        AttachWindow<ResourceWindow>();
        AttachWindow<InspectorWindow>();
    }

    void EditorLayer::OnGuiFrame(){

    }

    void EditorLayer::Switch2D()
    {
        if(Application::Get().m_Switch2D)
                Application::Get().m_Switch2D = false;
            else{
                Application::Get().m_Switch2D = true;
            }
            FS_INFO("{0}", Application::Get().m_Switch2D);
    }
}