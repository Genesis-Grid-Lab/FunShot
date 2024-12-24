#pragma once

#include "Helpers.h"

namespace FS {

    struct SelectEvent
    {
        inline SelectEvent(EntityID entity) : EnttID(entity)
        {}

        EntityID EnttID;
    };

    struct ASelectEvent{
        inline ASelectEvent(AssetID asset) : m_Asset(asset)
        {}

        AssetID m_Asset;
    };
}