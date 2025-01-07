#include "fspch.h"
#include "Engine/Core/Window.h"

#ifdef FS_PLATFORM_WINDOWS
	#include "Platform/Windows/WindowsWindow.h"
#endif

namespace FS
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
	#ifdef FS_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
	#else
		FS_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
	#endif
	}

}