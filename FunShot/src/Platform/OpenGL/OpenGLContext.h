#pragma once

#include "Engine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace FS {
    class OpenGLContext : public GraphicsContext{
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        void Init() override;
        void SwapBuffers() override; 
    private:
        GLFWwindow* m_WindowHandle;
    };
}