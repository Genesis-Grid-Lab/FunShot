#pragma once

// #include "Core/FSCore.h"


namespace FS {

    struct WindowProps{

        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "FunShot Editor",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            :Title(title), Width(width), Height(height){}
    };

    class Window {
    public:
        Window(const WindowProps& props);
        ~Window();

    private:
        bool Init(const WindowProps& props);
        void Shutdown();
    };
}