#include "Core/Window.h"
// #include "Core/FSLog.h"

namespace FS {

    Window::Window(const WindowProps& props){
        if(!Init(props)){
            // FS_CORE_ERROR("Failed to init window");
        }
    }

    Window::~Window(){
        Shutdown();
    }

    bool Window::Init(const WindowProps& props){

        InitWindow(props.Width, props.Height, props.Title.c_str());
        SetWindowState(FLAG_WINDOW_RESIZABLE);
        SetTargetFPS(60);
        SetExitKey(NULL);
        return true;
    }

    void Window::Shutdown(){
        CloseWindow();
    }
}