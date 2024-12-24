#pragma once

// #include "Core/FSCore.h"
#include "Core/Timestep.h"

namespace FS {

    class  Layer {
    public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void OnAttach() {}
        virtual void OnDetach() {}
        virtual void OnUpdate(Timestep ts) {}
        virtual void OnImGuiRender() {}

        inline const std::string& GetName() const { return m_DebugName;}

    private:
        std::string m_DebugName;
    };
}