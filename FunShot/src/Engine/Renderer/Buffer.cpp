#include "fspch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace FS {
    
    Ref<VertexBuffer> VertexBuffer::Create(uint32_t size){
        switch(Renderer::GetAPI()){
            case RendererAPI::API::None:         FS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:       return std::make_shared<OpenGLVertexBuffer>(size);
        }

        FS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<VertexBuffer> VertexBuffer::Create(float *vertices, uint32_t size){
        switch(Renderer::GetAPI()){
            case RendererAPI::API::None:         FS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:       return std::make_shared<OpenGLVertexBuffer>(vertices, size);
        }

        FS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::Create(uint32_t *indices, uint32_t count){
        switch(Renderer::GetAPI()){
            case RendererAPI::API::None:         FS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::API::OpenGL:       return std::make_shared<OpenGLIndexBuffer>(indices, count);
        }

        FS_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}