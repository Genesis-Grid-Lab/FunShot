#pragma once

#ifdef FS_PLATFORM_WINDOW

extern FS::Application* FS::CreateApplication();

int main(int argc, char** argv){

    FS::Log::Init();
    FS_CORE_WARN("init log!");
    int a = 10;
    FS_INFO("hello world {}", a);
    auto app = FS::CreateApplication();
    app->Run();
    delete app;

    return 0;
}
#endif