#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <array>

#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Engine/Core/Log.h"
#include "Engine/Debug/Instrumentor.h"

#ifdef FS_PLATFORM_WINDOWS
    #ifndef NOMINMAX
    # define NOMINMAX
    #endif
    #include <Windows.h>
#endif