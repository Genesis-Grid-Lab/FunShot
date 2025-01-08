#include "fspch.h"
#include "Engine/Core/Window.h"

#ifdef FS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif
#ifdef FS_PLATFORM_LINUX
	#include "Platform/Linux/LinuxWindow.h"
#endif

namespace FS
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef FS_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#endif
	#ifdef FS_PLATFORM_LINUX
	    return CreateScope<LinuxWindow>(props);
	#endif
		FS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	
	}

}