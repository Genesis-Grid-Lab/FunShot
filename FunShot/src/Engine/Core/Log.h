#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace FS {
    class FS_API Log{
    public:
        static void Init();

        inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
        inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
    private:
        static Ref<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
    };
}

//core log macros
#define FS_CORE_TRACE(...)              ::FS::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define FS_CORE_INFO(...)               ::FS::Log::GetCoreLogger()->info(__VA_ARGS__)
#define FS_CORE_WARN(...)               ::FS::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define FS_CORE_ERROR(...)              ::FS::Log::GetCoreLogger()->error(__VA_ARGS__)
#define FS_CORE_FATAL(...)              ::FS::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define FS_TRACE(...)               ::FS::Log::GetClientLogger()->trace(__VA_ARGS__)
#define FS_INFO(...)                ::FS::Log::GetClientLogger()->info(__VA_ARGS__)
#define FS_WARN(...)                ::FS::Log::GetClientLogger()->warn(__VA_ARGS__)
#define FS_ERROR(...)               ::FS::Log::GetClientLogger()->error(__VA_ARGS__)
#define FS_FATAL(...)               ::FS::Log::GetClientLogger()->fatal(__VA_ARGS__)