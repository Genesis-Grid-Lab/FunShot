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
    }

    bool Init(){
        if(!glfwInit()){
            FN_FATAL("failed to init glfw\n");
            return false;
        }

        mHandle = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);

        if(!mHandle){
            FN_FATAL("failed to create window\n");
            return false;
        }

        glfwMakeContextCurrent(mHandle);
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