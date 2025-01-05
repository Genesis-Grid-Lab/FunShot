#include "EditorLayer.h"
#include "imgui.h"
#include <glm/gtc/type_ptr.hpp>
#include "Engine/Scene/SceneSerializer.h"
#include "Engine/Utils/PlatformUtils.h"
#include "Engine/Math/Math.h"
#include "ImGuizmo.h"

namespace FS {

    EditorLayer::EditorLayer()
        :Layer("Editor"){
    }

    void EditorLayer::OnAttach()
    {
        FS_PROFILE_FUNCTION();
        m_Texture = Texture2D::Create("Resources/Textures/Checkerboard.png");

        FramebufferSpecification fbSpecification;
        fbSpecification.Attachments = { FramebufferTextureFormat::RGBA8, FramebufferTextureFormat::Depth};
        fbSpecification.Width = 1280;
        fbSpecification.Height = 720;
        m_Framebuffer = Framebuffer::Create(fbSpecification);

        m_ActiveScene = CreateRef<Scene>();
        m_EditorCamera = EditorCamera(30.0f, 1.778f, 0.1f, 1000.0f);
#if 0
        auto square = m_ActiveScene->CreateEntity("Turquoise square");
        square.AddComponent<SpriteRendererComponent>(glm::vec4{0.0f, 1.0f, 0.7f, 1.0f});

        auto redSquare = m_ActiveScene->CreateEntity("Red Square");
        redSquare.AddComponent<SpriteRendererComponent>(glm::vec4{1.0f, 0.0f, 0.0f, 1.0f});

        m_SquareEntity = square;

        m_CameraEntity = m_ActiveScene->CreateEntity("Camera A");
        m_CameraEntity.AddComponent<CameraComponent>();

        m_SecondCamera = m_ActiveScene->CreateEntity("Camera B");
        auto& cc = m_SecondCamera.AddComponent<CameraComponent>();
        cc.Primary = false;

        class CameraController : public ScriptableEntity {
        public:
            void OnCreate(){                
                
            }

            void OnDestroy(){

            }

            void OnUpdate(Timestep ts){
                auto& tc = GetComponent<TransformComponent>();
                float speed = 5.0f;
                if(Input::IsKeyPressed(FS_KEY_A))
                    tc.Translation.x -= speed * ts;
                if(Input::IsKeyPressed(FS_KEY_D))
                    tc.Translation.x += speed * ts;
                if(Input::IsKeyPressed(FS_KEY_W))
                    tc.Translation.y += speed * ts;
                if(Input::IsKeyPressed(FS_KEY_S))
                    tc.Translation.y -= speed * ts;
            }
        };

        class SecondController : public ScriptableEntity{
        public:
            void OnCreate(){
                auto& tc = GetComponent<TransformComponent>();
                tc.Translation.x = 1.0f;
                tc.Translation.y = 1.0f;
                
            }
        };
        m_CameraEntity.AddComponent<NativeScriptComponent>().Bind<CameraController>();     
        redSquare.AddComponent<NativeScriptComponent>().Bind<SecondController>();  
#endif
        m_SceneHierarachyPanel.SetContext(m_ActiveScene);                
    }

    void EditorLayer::OnDetach(){
        FS_PROFILE_FUNCTION();
    }  

    void EditorLayer::OnUpdate(Timestep ts){
        
        FramebufferSpecification spec = m_Framebuffer->GetSpecification();
        if(m_ViewportSize.x > 0.0f && m_ViewportSize.y > 0.0f &&
            (spec.Width != m_ViewportSize.x || spec.Height != m_ViewportSize.y)){
            
            m_Framebuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
            m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);  
            m_EditorCamera.SetViewportSize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
        } 
        if(m_ViewportSize.x > 0.0f && m_ViewportSize.y > 0.0f ){
            
            m_Framebuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
            m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);  
            m_EditorCamera.SetViewportSize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
        }           
          
        m_EditorCamera.OnUpdate(ts);

        Renderer2D::ResetStats();             
        m_Framebuffer->Bind();
        RenderCommand::SetClearColor({0.1,0.1,0.1,1});
        RenderCommand::Clear();
                 
        //update scene
        m_ActiveScene->OnUpdateEditor(ts, m_EditorCamera);
        // m_ActiveScene->OnUpdateRuntime(ts);

        m_Framebuffer->Unbind();
    

    }

    void EditorLayer::OnImGuiRender(){
        FS_PROFILE_FUNCTION();

        static bool p_open = true;
        static bool opt_fullscreen = true;
        static bool opt_padding = false;
        static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

        // We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
        // because it would be confusing to have two docking targets within each others.
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
        if (opt_fullscreen)
        {
            const ImGuiViewport* viewport = ImGui::GetMainViewport();
            ImGui::SetNextWindowPos(viewport->WorkPos);
            ImGui::SetNextWindowSize(viewport->WorkSize);
            ImGui::SetNextWindowViewport(viewport->ID);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
            ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
            window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
            window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        }
        else
        {
            dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
        }

        // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
        // and handle the pass-thru hole, so we ask Begin() to not render a background.
        if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
            window_flags |= ImGuiWindowFlags_NoBackground;

        // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
        // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
        // all active windows docked into it will lose their parent and become undocked.
        // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
        // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
        if (!opt_padding)
            ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace", &p_open, window_flags);
        if (!opt_padding)
            ImGui::PopStyleVar();

        if (opt_fullscreen)
            ImGui::PopStyleVar(2);

        // Submit the DockSpace
        ImGuiIO& io = ImGui::GetIO();
        ImGuiStyle& style = ImGui::GetStyle();
        float minWinSizeX = style.WindowMinSize.x;
        style.WindowMinSize.x = 370.0f;
        if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
        {
            ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
            ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
        }

        style.WindowMinSize.x = minWinSizeX;           

        if (ImGui::BeginMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                // Disabling fullscreen would allow the window to be moved to the front of other windows,
                // which we can't undo at the moment without finer window depth/z control.
                if(ImGui::MenuItem("New", "Ctrl+N")){
                    NewScene();
                }

                if(ImGui::MenuItem("Open...", "Ctrl+O")){
                    OpenScene();
                }

                if(ImGui::MenuItem("Save As...", "Ctrl+Shift+S")){
                    SaveSceneAs();

                }

                if(ImGui::MenuItem("Exit")) Application::Get().Close();

                ImGui::EndMenu();
            }

            ImGui::EndMenuBar();
        }

        m_SceneHierarachyPanel.OnImGuiRender();

        ImGui::Begin("Stats");

        auto stats = FS::Renderer2D::GetStats();
        ImGui::Text("Renderer2D Stats:");
        ImGui::Text("Draw Calls: %d", stats.DrawCalls);
        ImGui::Text("Quads: %d", stats.QuadCount);
        ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
        ImGui::Text("Indices: %d", stats.GetTotalIndexCount());

        ImGui::End();

        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2{0,0});
        ImGui::Begin("ViewPort");
        m_ViewportFocused = ImGui::IsWindowFocused();
        m_ViewportHovered = ImGui::IsWindowHovered();
        Application::Get().GetImGuiLayer()->BlockEvents(!m_ViewportFocused && !m_ViewportHovered);
        ImVec2 viewPortPanelSize = ImGui::GetContentRegionAvail();

        if(m_ViewportSize != *((glm::vec2*)&viewPortPanelSize)){
            m_ViewportSize = {viewPortPanelSize.x, viewPortPanelSize.y};
            m_Framebuffer->Resize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);

            // m_CameraController.Resize(viewPortPanelSize.x, viewPortPanelSize.y);
        }
        ImTextureID textureID = m_Framebuffer->GetColorAttachmentRendererID();
        ImGui::Image(textureID, ImVec2{m_ViewportSize.x, m_ViewportSize.y}, ImVec2{0, 1}, ImVec2{1,0});

        //Gizmos
        Entity selectedEntity = m_SceneHierarachyPanel.GetSelectedEntity();
        if(selectedEntity && m_GismoType != -1){
            ImGuizmo::SetOrthographic(false);
            ImGuizmo::SetDrawlist();

            float windowWidth = (float)ImGui::GetWindowWidth();
            float windowHeight = (float)ImGui::GetWindowHeight();
            ImGuizmo::SetRect(ImGui::GetWindowPos().x, ImGui::GetWindowPos().y, windowWidth, windowHeight);

            //camera
            //runtimwe
            // auto cameraEntity = m_ActiveScene->GetPrimaryCameraEntity();
            // const auto& camera = cameraEntity.GetComponent<CameraComponent>().Camera;
            // const glm::mat4& cameraProjection = camera.GetProjection();
            // glm::mat4 cameraView = glm::inverse(cameraEntity.GetComponent<TransformComponent>().GetTransform());

            //Editor camera
            const glm::mat4& cameraProjection = m_EditorCamera.GetProjection();
            glm::mat4 cameraView = m_EditorCamera.GetViewMatrix();

            //Entity transform
            auto& tc = selectedEntity.GetComponent<TransformComponent>();
            glm::mat4 transform = tc.GetTransform();
            
            // Snapping
			bool snap = Input::IsKeyPressed(FS_KEY_LEFT_CONTROL);
			float snapValue = 0.5f; // Snap to 0.5m for translation/scale
			// Snap to 45 degrees for rotation
			if (m_GismoType == ImGuizmo::OPERATION::ROTATE)
				snapValue = 45.0f;

			float snapValues[3] = { snapValue, snapValue, snapValue };

			ImGuizmo::Manipulate(glm::value_ptr(cameraView), glm::value_ptr(cameraProjection),
				(ImGuizmo::OPERATION)m_GismoType, ImGuizmo::LOCAL, glm::value_ptr(transform),
				nullptr, snap ? snapValues : nullptr);

            if(ImGuizmo::IsUsing()){
                glm::vec3 translation, rotation, scale;
                Math::DecomposeTransform(transform, translation, rotation, scale);

                glm::vec3 deltaRotation = rotation - tc.Rotation;
                tc.Translation = translation;
                tc.Rotation += deltaRotation;
                tc.Scale = scale;
            }         
        }

        ImGui::End();
        ImGui::PopStyleVar();

        ImGui::End();
    }

    void EditorLayer::OnEvent(Event &event){
        // m_CameraController.OnEvent(event);
        m_EditorCamera.OnEvent(event);

        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<KeyPressedEvent>(BIND_EVENT_FN(EditorLayer::OnKeyPressed));
    }

    bool EditorLayer::OnKeyPressed(KeyPressedEvent &e){
        if(e.GetRepeatCount() > 0)
            return false;

        bool control = Input::IsKeyPressed(FS_KEY_LEFT_CONTROL) || Input::IsKeyPressed(FS_KEY_RIGHT_CONTROL);
        bool shift = Input::IsKeyPressed(FS_KEY_LEFT_SHIFT) || Input::IsKeyPressed(FS_KEY_RIGHT_SHIFT);
        switch(e.GetKeyCode()){
            case FS_KEY_S:            
            {
                if(control && shift){
                    SaveSceneAs();
                }
                break;
            }
            case FS_KEY_N:            
            {
                if(control){
                    NewScene();
                }
                break;
            }
            case FS_KEY_O:            
            {                
                if(control){
                    OpenScene();
                }
                break;
            }

            //Gizmo
            case FS_KEY_Q:
            {
                m_GismoType = -1;
                break;
            }
            case FS_KEY_W:
            {                
                m_GismoType = ImGuizmo::OPERATION::TRANSLATE;
                break;
            }
            case FS_KEY_E:
            {
                m_GismoType = ImGuizmo::OPERATION::SCALE;
                break;
            }
            case FS_KEY_R:
            {
                m_GismoType = ImGuizmo::OPERATION::ROTATE;
                break;
            }
        }
        return false;
    }

    void EditorLayer::NewScene(){
        m_ActiveScene = CreateRef<Scene>();
        m_ActiveScene->OnViewportResize((uint32_t)m_ViewportSize.x, (uint32_t)m_ViewportSize.y);
        m_SceneHierarachyPanel.SetContext(m_ActiveScene);
    }

    void EditorLayer::OpenScene(){
        std::string filepath = FileDialogs::OpenFile("FunShot Scene (*.FunShot)\0*.FunShot\0");
        if(!filepath.empty()){
            NewScene();
            SceneSerializer serializer(m_ActiveScene);  
            serializer.Deserialize(filepath);    
        }
    }

    void EditorLayer::SaveSceneAs(){
        std::string filepath = FileDialogs::SaveFile("FunShot Scene (*.FunShot)\0*.FunShot\0");
        if(!filepath.empty()){
            SceneSerializer serializer(m_ActiveScene);  
            serializer.Serialize(filepath);
        }
    }
}
