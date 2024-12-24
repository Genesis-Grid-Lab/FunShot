#include "fspch.h"
#include "Renderer/Renderer.h"

namespace FS {

    Renderer::Renderer(){
        m_Buffer3D = CreateScope<Framebuffer>(GetScreenWidth(), GetScreenHeight());
        m_Buffer2D = CreateScope<Framebuffer>(GetScreenWidth(), GetScreenHeight());
        m_BufferPlay = CreateScope<Framebuffer>(GetScreenWidth(), GetScreenHeight());

        m_GlobalCam.position = Vector3{1.0f, 1.0f, 1.0f};
        m_GlobalCam.target = Vector3{4.0f, 1.0f, 4.0f};
        m_GlobalCam.up = Vector3{0.0f, 1.0f, 0.0f};
        m_GlobalCam.fovy = 45.0f;
        m_GlobalCam.projection = CAMERA_PERSPECTIVE;
    }

    Renderer::~Renderer(){
    }

    void Renderer::Update(){
        m_Buffer3D->Resize();
        m_Buffer2D->Resize();
        m_BufferPlay->Resize();
        UpdateCamera(&m_GlobalCam, CAMERA_FREE); 
    }

    const Scope<Framebuffer> &Renderer::GetBuffer(Buffer buffer) const{
        switch(buffer){
            case e_Play:
                return m_BufferPlay;
                break;
            case e_2D:
                return m_Buffer2D;
                break;
            case e_3D:
                return m_Buffer3D;
                break;
        }

        FS_CORE_ERROR("Wrong buffer name");
        return nullptr;
    }
}

