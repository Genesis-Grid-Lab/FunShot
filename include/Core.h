#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <string>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

// include spdlog
// #define FMT_HEADER_ONLY
// #define SPDLOG_FMT_EXTERNAL
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

// glm
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtx/quaternion.hpp>

#include <entt/entt.hpp>

using EntityID = entt::entity;
using EntityRegistry = entt::registry;
constexpr EntityID NENTT = entt::null;

// console logging
struct Logger {
  using SPDLog = std::shared_ptr<spdlog::logger>;

  inline Logger() {
    m_SPD = spdlog::stdout_color_mt("stdout");
    spdlog::set_level(spdlog::level::trace);
    spdlog::set_pattern("%^[%T]: [#%t] %v%$");
  }

  inline static SPDLog &Ref() {
    static Logger logger;
    return logger.m_SPD;
  }

private:
  SPDLog m_SPD;
};

static void GLClearAllErrors() {
  while (glGetError() != GL_NO_ERROR) {
  }
}

static bool GLCheckErrorStatus(const char *function, int line) {
  while (GLenum error = glGetError()) {

    std::string code;

    switch (error) {
    case GL_INVALID_ENUM:
      code = "INVALID_ENUM";
      break;
    case GL_INVALID_VALUE:
      code = "INVALID_VALUE";
      break;
    case GL_INVALID_OPERATION:
      code = "INVALID_OPERATION";
      break;
    case GL_STACK_OVERFLOW:
      code = "STACK_OVERFLOW";
      break;
    case GL_STACK_UNDERFLOW:
      code = "STACK_UNDERFLOW";
      break;
    case GL_OUT_OF_MEMORY:
      code = "OUT_OF_MEMORY";
      break;
    case GL_INVALID_FRAMEBUFFER_OPERATION:
      code = "INVALID_FRAMEBUFFER_OPERATION";
      break;
    }
    std::cout << code << " | " << function << " (" << line << ")" << std::endl;
    return true;
  }
  return false;
}

// logging macros
#ifdef ENABLE_LOG
#define FN_TRACE(...) Logger::Ref()->trace(__VA_ARGS__)
#define FN_DEBUG(...) Logger::Ref()->debug(__VA_ARGS__)
#define FN_INFO(...) Logger::Ref()->info(__VA_ARGS__)
#define FN_WARN(...) Logger::Ref()->warn(__VA_ARGS__)
#define FN_ERROR(...) Logger::Ref()->error(__VA_ARGS__)
#define FN_FATAL(...) Logger::Ref()->critical(__VA_ARGS__)
#define GLCheck(x)                                                             \
  GLClearAllErrors();                                                     \
  x;                                                                           \
  GLCheckErrorStatus(#x, __LINE__);
#else
#define FN_TRACE
#define FN_DEBUG
#define FN_ERROR
#define FN_FATAL
#define FN_INFO
#define FN_WARN
#define GLCheck(x)
#endif