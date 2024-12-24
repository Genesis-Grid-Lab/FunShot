#pragma once
#if 1
extern FS::Application* FS::CreateApplication();

int main(int argc, char** argv){

    FS::FSLog::Init();
    // FS_PROFILE_BEGIN_SESSION("Startup", "FSProfile-Startup.json");
    auto app = FS::CreateApplication();
    // FS_PROFILE_END_SESSION();

    // FS_PROFILE_BEGIN_SESSION("Runtime", "FSProfile-Runtime.json");
    app->Run();
    // FS_PROFILE_END_SESSION();

    // FS_PROFILE_BEGIN_SESSION("Shutdown", "FSProfile-Shutdown.json");
    delete app;
    // FS_PROFILE_END_SESSION();

    return 0;
}

#endif