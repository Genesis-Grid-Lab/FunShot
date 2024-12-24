#pragma once

#include "Renderer/Framebuffer.h"

namespace FS {

    class Renderer{
    public:
        enum Buffer {
            e_Play = 0,
            e_3D,
            e_2D
        };

        Renderer();
        ~Renderer();

        void Update();
        
        const Scope<Framebuffer>& GetBuffer(Buffer buffer) const;

        Camera3D m_GlobalCam = {0};
    private:
        Scope<Framebuffer> m_Buffer3D;
        Scope<Framebuffer> m_Buffer2D;
        Scope<Framebuffer> m_BufferPlay;
    };
}