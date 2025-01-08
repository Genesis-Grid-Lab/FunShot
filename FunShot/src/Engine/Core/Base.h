#pragma once

#include <memory>
#if defined(__GNUC__) && !defined(NDEBUG) && defined(__OPTIMIZE__)
    #warning "Undefing __OPTIMIZE__ because of fmt"
    #undef __OPTIMIZE__
#endif

#include "Engine/Core/PlatformDetection.h"

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

#define BIT(x) (1 << x)

#define FS_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace FS {

	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}

#include "Engine/Core/Log.h"
#include "Engine/Core/Assert.h"
