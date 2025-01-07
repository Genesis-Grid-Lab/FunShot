#pragma once
#include "Engine/Core/Base.h"
#include "Engine/Core/Application.h"

#ifdef FS_PLATFORM_WINDOWS

extern FS::Application* FS::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	FS::Log::Init();

	FS_PROFILE_BEGIN_SESSION("Startup", "FSProfile-Startup.json");
	auto app = FS::CreateApplication({ argc, argv });
	FS_PROFILE_END_SESSION();

	FS_PROFILE_BEGIN_SESSION("Runtime", "FSProfile-Runtime.json");
	app->Run();
	FS_PROFILE_END_SESSION();

	FS_PROFILE_BEGIN_SESSION("Shutdown", "FSProfile-Shutdown.json");
	delete app;
	FS_PROFILE_END_SESSION();
}

#endif
