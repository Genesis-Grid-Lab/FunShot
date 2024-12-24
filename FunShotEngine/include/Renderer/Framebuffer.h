#pragma once

// #include "Core/FSCore.h"

namespace FS {

    class Framebuffer {
    public:
        Framebuffer(int width, int height);
        ~Framebuffer();

        void Resize();

        void Bind();
        void Unbind();

        RenderTexture &GetTexture() { return m_ViewTexture;}
    private:
        int m_Width, m_Height;
        RenderTexture m_ViewTexture;
    };
}