#pragma once

#include "Engine/Core/PlatformDetection.h"

#include <memory>

#ifdef FS_DEBUG
	#if defined(FS_PLATFORM_WINDOWS)
		#define FS_DEBUGBREAK() __debugbreak()
	#elif defined(FS_PLATFORM_LINUX)
		#include <signal.h>
		#define FS_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define FS_ENABLE_ASSERTS
#else
	#define FS_DEBUGBREAK()
#endif

#define FS_EXPAND_MACRO(x) x
#define FS_STRINGIFY_MACRO(x) #x

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define BIT(x) (1 << x)

namespace FS {
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args){
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args){
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}

#include "Engine/Core/Assert.h"