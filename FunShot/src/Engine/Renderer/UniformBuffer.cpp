#include "fspch.h"
#include "UniformBuffer.h"

#include "Engine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLUniformBuffer.h"

namespace FS {

	Ref<UniformBuffer> UniformBuffer::Create(uint32_t size, uint32_t binding)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    FS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLUniformBuffer>(size, binding);
		}

		FS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}