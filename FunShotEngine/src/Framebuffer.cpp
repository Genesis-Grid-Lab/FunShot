#include "fspch.h"
#include "Renderer/Framebuffer.h"

namespace FS {

    Framebuffer::Framebuffer(int width, int height)
        : m_Width(width), m_Height(height){
        m_ViewTexture = LoadRenderTexture(m_Width, m_Height);
    }

    Framebuffer::~Framebuffer(){
        UnloadRenderTexture(m_ViewTexture);
    }

    void Framebuffer::Resize(){
        if (IsWindowResized())
		{
			UnloadRenderTexture(m_ViewTexture);
			m_ViewTexture = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
		}
    }

    void Framebuffer::Bind(){
        BeginTextureMode(m_ViewTexture);
    }

    void Framebuffer::Unbind(){
        EndTextureMode();
    }
}