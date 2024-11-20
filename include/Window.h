#pragma once
#include "Core.h"

class Window {
public:
    Window(const char* title, int width, int height) :
    mTitle(title), mWidth(width), mHeight(height){

    }
    ~Window(){
        FN_INFO("destroy window class");
        glfwDestroyWindow(mHandle);
        glfwTerminate();
    }

    bool Init(){
        if(!glfwInit()){
            FN_FATAL("failed to init glfw\n");
            return false;
        }

        glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_TRUE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

        auto display = glfwGetVideoMode(glfwGetPrimaryMonitor());
        glfwWindowHint(GLFW_REFRESH_RATE, display->refreshRate);
        glfwWindowHint(GLFW_GREEN_BITS, display->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, display->blueBits);
        glfwWindowHint(GLFW_RED_BITS, display->redBits);
        glfwWindowHint(GLFW_SAMPLES, 4);

        glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);

        mHandle = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);

        if(!mHandle){
            FN_FATAL("failed to create window\n");
            return false;
        }

        glfwMakeContextCurrent(mHandle);

         glfwSwapInterval(1);
        return true;
    }

    bool PollEvents(){
        glfwSwapBuffers(mHandle);
        glfwPollEvents();

        return !glfwWindowShouldClose(mHandle);
    }

    GLFWwindow *Handle() { return mHandle;}

private:
    GLFWwindow *mHandle;
    int mWidth, mHeight;
    const char* mTitle;
};
