#include "fspch.h"
#include "RenderCommand.h"
#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace FS {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();
}