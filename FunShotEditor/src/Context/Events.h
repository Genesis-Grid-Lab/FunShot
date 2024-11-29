#pragma once

#include "Helpers.h"

struct SelectEvent
{
    GEN_INLINE SelectEvent(EntityID entity) : EnttID(entity)
    {}

    EntityID EnttID;
};