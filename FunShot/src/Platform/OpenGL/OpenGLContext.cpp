#include "fspch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace FS {
    OpenGLContext::OpenGLContext(GLFWwindow *windowHandle) : m_WindowHandle(windowHandle){
        FS_CORE_ASSERT(windowHandle, "Window handle is null");
    }

    void OpenGLContext::Init(){

        glfwMakeContextCurrent(m_WindowHandle);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        FS_CORE_ASSERT(status, "Failed to init Glad!");

        std::string vendor = std::string((const char*)glGetString(GL_VENDOR));
        std::string version = std::string((const char*)glGetString(GL_VERSION));
        std::string renderer = std::string((const char*)glGetString(GL_RENDERER));
        FS_CORE_INFO("OpenGL Info:");
        FS_CORE_INFO(" Vendor: {0}", vendor);
        FS_CORE_INFO(" Renderer: {0}", renderer);
        FS_CORE_INFO(" version: {0}", version);
    }

    void OpenGLContext::SwapBuffers(){
        glfwSwapBuffers(m_WindowHandle);
    }
}