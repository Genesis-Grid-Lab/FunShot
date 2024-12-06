#include "fspch.h"
#include "VertexArray.h"

#include "Engine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace FS {

    VertexArray* VertexArray::Create(){
        switch(Renderer::GetAPI()){
            case RendererAPI::API::None:         FS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:       return new OpenGLVertexArray();
        }

        FS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}