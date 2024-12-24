#pragma once

#include "Core/Layer.h"
#include "Core/Timestep.h"
#include "Widget.h"

namespace FS {

    class EditorLayer : public Layer {
    public:
        EditorLayer();
        ~EditorLayer() = default;
        void OnAttach() override;
        void OnDetach() override;
        void OnUpdate(Timestep ts) override;
        void OnImGuiRender() override;

        virtual void OnGuiStart();
        virtual void OnGuiFrame();

        template<typename T, typename... Args>
        inline void AttachWindow(Args&&... args)
        {
            // GEN_STATIC_ASSERT(std::is_base_of<IWidget, T>::value);
            auto window = std::make_unique<T>(this, std::forward<Args>(args)...);
            m_Windows.push_back(std::move(window));
        }

        template<typename T, typename... Args>
        inline auto CreateWidget(Args&&... args)
        {
            // GEN_STATIC_ASSERT(std::is_base_of<IWidget, T>::value);
            auto widget = std::make_unique<T>(this, std::forward<Args>(args)...);
            return widget;
        }

    //TEMP        
        bool m_ViewportFocused = false;
        bool m_ViewportHovered = false;
        bool m_Switch2D = false;

        void Switch2D();
    private:    
        std::vector<Widget> m_Windows;
        Image image;
        Texture2D cubicmap;
        Mesh mesh;
        Model model;
        Texture2D texture;
    };
}