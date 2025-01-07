#include "fspch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace FS {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		FS_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		FS_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FS_CORE_ASSERT(status, "Failed to initialize Glad!");

		FS_CORE_INFO("OpenGL Info:");
		FS_CORE_INFO("  Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		FS_CORE_INFO("  Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		FS_CORE_INFO("  Version: {0}", (const char*)glGetString(GL_VERSION));

		FS_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "FunShot requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		FS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}
