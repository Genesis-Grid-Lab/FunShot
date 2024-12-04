#pragma once

#ifdef FS_PLATFORM_WINDOW
    #if defined(FS_BUILD_DLL)
        #define FS_API __declspec(dllexport)
    #elif defined(FS_NO_DLL)
        #define FS_API
    #else
        #define FS_API __declspec(dllimport)
    #endif
#else
    #error NO OTHER SUPPORT FOR NOW
#endif

#ifdef FS_DEBUG
    #define FS_ENABLE_ASSERTS
#endif

#ifdef FS_ENABLE_ASSERTS
    #define FS_ASSERT(x, ...) { if(!(x)) { FS_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
    #define FS_CORE_ASSERT(x, ...) { if(!(x)) { FS_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();} }
#else
    #define FS_ASSERT(x, ...)
    #define FS_CORE_ASSERT(x, ...)
#endif

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)

#define BIT(x) (1 << x)