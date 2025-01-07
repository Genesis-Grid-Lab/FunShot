#include "fspch.h"
#include "Engine/Renderer/RenderCommand.h"

namespace FS {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}