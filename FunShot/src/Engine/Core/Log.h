#pragma once

#include "Engine/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace FS {

	class Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternio)
{
	return os << glm::to_string(quaternio);
}

// Core log macros
#define FS_CORE_TRACE(...)    ::FS::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FS_CORE_INFO(...)     ::FS::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FS_CORE_WARN(...)     ::FS::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FS_CORE_ERROR(...)    ::FS::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FS_CORE_CRITICAL(...) ::FS::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define FS_TRACE(...)         ::FS::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FS_INFO(...)          ::FS::Log::GetClientLogger()->info(__VA_ARGS__)
#define FS_WARN(...)          ::FS::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FS_ERROR(...)         ::FS::Log::GetClientLogger()->error(__VA_ARGS__)
#define FS_CRITICAL(...)      ::FS::Log::GetClientLogger()->critical(__VA_ARGS__)