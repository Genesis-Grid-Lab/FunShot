#pragma once

#include "Events.h"
#include "Inputs.h"

//foward decl
struct GuiContext;

// widget interface
struct IWidget
{
    GEN_INLINE IWidget(GuiContext*) {};
    GEN_INLINE virtual ~IWidget() = default;
    GEN_INLINE virtual void OnSelect(Entity) {}
    GEN_INLINE virtual void OnShow(GuiContext*) {}
    GEN_INLINE virtual void SetTitle(const char*) {}
};

//widget type definition
using Widget = std::unique_ptr<IWidget>;