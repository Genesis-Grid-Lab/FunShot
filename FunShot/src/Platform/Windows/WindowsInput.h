#pragma once

#include "Engine/Core/Input.h"

namespace FS {

    class WindowsInput : public Input{
    protected:
        bool IsKeyPressedImpl(int keycode) override;
        bool IsMouseButtonPressedImpl(int button) override;

        std::pair<float, float> GetMousePositionImpl() override;
        float GetMouseXImpl() override;
        float GetMouseYImpl() override;
    };
}