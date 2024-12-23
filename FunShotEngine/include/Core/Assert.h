#pragma once

// #include "Core/FSCore.h"
#include "Core/FSLog.h"
#include <filesystem>

#ifdef FS_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define FS_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { FS##type##ERROR(msg, __VA_ARGS__); FS_DEBUGBREAK(); } }
	#define FS_INTERNAL_ASSERT_WITH_MSG(type, check, ...) FS_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define FS_INTERNAL_ASSERT_NO_MSG(type, check) FS_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", FS_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

	#define FS_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define FS_INTERNAL_ASSERT_GET_MACRO(...) FS_EXPAND_MACRO( FS_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, FS_INTERNAL_ASSERT_WITH_MSG, FS_INTERNAL_ASSERT_NO_MSG) )

	// Currently accepts at least the condition and one additional parameter (the message) being optional
	#define FS_ASSERT(...) FS_EXPAND_MACRO( FS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
	#define FS_CORE_ASSERT(...) FS_EXPAND_MACRO( FS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
	#define FS_ASSERT(...)
	#define FS_CORE_ASSERT(...)
#endif