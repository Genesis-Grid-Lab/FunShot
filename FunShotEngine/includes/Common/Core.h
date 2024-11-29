#pragma once
#include <queue>
#include <vector>
#include <string>
#include <bitset>
#include <random>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <filesystem>
#include <unordered_map>
#include <iostream>

// include glew
#define GLEW_STATIC
#include <GL/glew.h>

// include entt
#include <entt/entt.hpp>

// include magic enum
#include <magic_enum/magic_enum.hpp>

// include glm
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/matrix_clip_space.hpp>

// include spdlog
// #define FMT_HEADER_ONLY 
// #define SPDLOG_FMT_EXTERNAL
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

// import, export
#ifdef GEN_EXPORT
    #ifdef _MSC_VER
        #define GEN_API __declspec(dllexport)
    #else
        #define GEN_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define GEN_API __declspec(dllimport)
    #else
        #define GEN_API
    #endif
#endif

// runtime assertion
#define GEN_ASSERT assert

// compile assertion
#if defined(__clang__) || defined(__gcc__)
    #define GEN_STATIC_ASSERT _Static_assert
#else
    #define GEN_STATIC_ASSERT static_assert
#endif

// function inlining
#if defined(__clang__) || defined(__gcc__)
    #define GEN_INLINE __attribute__((always_inline)) inline
    #define GEN_NOINLINE __attribute__((noinline))
#elif defined(_MSC_VER)
    #define GEN_INLINE __forceinline
    #define GEN_NOINLINE __declspec(noinline)
#else
    #define GEN_INLINE inline
    #define GEN_NOINLINE
#endif

// core features
namespace Gen
{
    // entity identifier
    using EntityID = entt::entity;
    // null entity
    constexpr EntityID NENTT = entt::null;  
    // entity registry
    using EntityRegistry = entt::registry;

    // runtime type
    template <typename T>
    GEN_INLINE constexpr uint32_t TypeID()
    {
        return static_cast<uint32_t>(reinterpret_cast<std::uintptr_t>(&typeid(T)));
    }

    // generate random 64 bit
    GEN_INLINE uint64_t RandomU64() 
    {
        static std::random_device device;
        static std::mt19937_64 generator(device());
        static std::uniform_int_distribution<uint64_t> distribution;
        return distribution(generator);
    }

    // console logging
    struct GEN_API Logger 
    { 
        using SPDLog = std::shared_ptr<spdlog::logger>;

        GEN_INLINE Logger()
        {
            m_SPD = spdlog::stdout_color_mt("stdout");
            spdlog::set_level(spdlog::level::trace);              
            spdlog::set_pattern("%^[%T]: [#%t] %v%$");
        }

        GEN_INLINE static SPDLog& Ref() 
        {
            static Logger logger;
            return logger.m_SPD;
        }   

    private:
        SPDLog m_SPD;         
    };

    static void GLClearAllErrors()
    {
      while (glGetError() != GL_NO_ERROR) {
        
      }
    }

    static bool GLCheckErrorStatus(const char* function, int line)
    {
      while (GLenum error = glGetError()) {
        /*std::cout << "OpenGL Error: " << error
                  << " Line: " << line
                  << " Function: " << function 
                  << std::endl;*/

        std::string code;

        switch (error)
        {
            case GL_INVALID_ENUM:                  code = "INVALID_ENUM"; break;
            case GL_INVALID_VALUE:                 code = "INVALID_VALUE"; break;
            case GL_INVALID_OPERATION:             code = "INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW:                code = "STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW:               code = "STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY:                 code = "OUT_OF_MEMORY"; break;
            case GL_INVALID_FRAMEBUFFER_OPERATION: code = "INVALID_FRAMEBUFFER_OPERATION"; break;
        }
        std::cout << code << " | " << function << " (" << line << ")" << std::endl;
        return true;
      }
      return false;
    }
}

#define GLCheck(x) Gen::GLClearAllErrors(); x; GLCheckErrorStatus(#x, __LINE__);

    // logging macros 
#ifdef GEN_ENABLE_LOG
    #define GEN_TRACE(...) Gen::Logger::Ref()->trace(__VA_ARGS__)
    #define GEN_DEBUG(...) Gen::Logger::Ref()->debug(__VA_ARGS__)
    #define GEN_INFO(...)  Gen::Logger::Ref()->info(__VA_ARGS__)
    #define GEN_WARN(...)  Gen::Logger::Ref()->warn(__VA_ARGS__)
    #define GEN_ERROR(...) Gen::Logger::Ref()->error(__VA_ARGS__)
    #define GEN_FATAL(...) Gen::Logger::Ref()->critical(__VA_ARGS__)
     
#else
	#define GEN_TRACE
	#define GEN_DEBUG
	#define GEN_ERROR	
	#define GEN_FATAL
	#define GEN_INFO
    #define GEN_WARN
    #define GLCheck(x)
#endif

// free allocated memory
#define GEN_DELETE(ptr) if (ptr != nullptr) { delete (ptr); ptr = nullptr; }
