#include "Core/FSLog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace FS {

    Ref<spdlog::logger> FSLog::s_CoreLogger;
    Ref<spdlog::logger> FSLog::s_ClientLogger;

    void FSLog::Init(){
        spdlog::set_pattern("%^[%T] %n: %v%$");
        s_CoreLogger = spdlog::stdout_color_mt("FunShot");
        s_CoreLogger->set_level(spdlog::level::trace);

        s_ClientLogger = spdlog::stdout_color_mt("APP");
        s_ClientLogger->set_level(spdlog::level::trace);
    }
}