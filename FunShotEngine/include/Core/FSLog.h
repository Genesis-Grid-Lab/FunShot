#pragma once

#include "FSCore.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace FS {
    class  FSLog{
    public:
        static void Init();

        inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
        // inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger;}
        inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
        // inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;}
    private:
        static Ref<spdlog::logger> s_CoreLogger;
        // static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static Ref<spdlog::logger> s_ClientLogger;
        // static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

//core log macros
#define FS_CORE_TRACE(...)              ::FS::FSLog::GetCoreLogger()->trace(__VA_ARGS__)
#define FS_CORE_INFO(...)               ::FS::FSLog::GetCoreLogger()->info(__VA_ARGS__)
#define FS_CORE_WARN(...)               ::FS::FSLog::GetCoreLogger()->warn(__VA_ARGS__)
#define FS_CORE_ERROR(...)              ::FS::FSLog::GetCoreLogger()->error(__VA_ARGS__)
#define FS_CORE_FATAL(...)              ::FS::FSLog::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define FS_TRACE(...)               ::FS::FSLog::GetClientLogger()->trace(__VA_ARGS__)
#define FS_INFO(...)                ::FS::FSLog::GetClientLogger()->info(__VA_ARGS__)
#define FS_WARN(...)                ::FS::FSLog::GetClientLogger()->warn(__VA_ARGS__)
#define FS_ERROR(...)               ::FS::FSLog::GetClientLogger()->error(__VA_ARGS__)
#define FS_FATAL(...)               ::FS::FSLog::GetClientLogger()->fatal(__VA_ARGS__)