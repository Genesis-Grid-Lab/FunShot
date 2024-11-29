cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# build output directories

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(CMAKE_PDB_OUTPUT_DIRECTORY $<0:>${CMAKE_BINARY_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH $<0:>${CMAKE_BINARY_DIR}/bin)

# cpp standard options

set(CMAKE_CONFIGURATION_TYPES Debug Release)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)
set(CMAKE_CXX_STANDARD 17)

project(FunShotEngine)

# enable console logging

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_definitions(-DGEN_ENABLE_LOG)
endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

add_subdirectory(Vendor/glfw)
add_subdirectory(Vendor/glew/build/cmake)
add_subdirectory(Vendor/glm)
add_subdirectory(Vendor/entt)
add_subdirectory(Vendor/assimp)
add_subdirectory(Vendor/spdlog)
add_subdirectory(Vendor/magic_enum)
add_subdirectory(Vendor/lua)
add_subdirectory(Vendor/sol2)
set(BUILD_SHARED_LIBS ON)
add_subdirectory(Vendor/yaml-cpp)

# project subdirectories

add_subdirectory(FunShotEngine)
add_subdirectory(FunShotEditor)
#add_subdirectory(FunShotGame)

if (MSVC)
  add_compile_options(/bigobj)
  #target_compile_options(${PROJECT_NAME} PRIVATE /bigobj)
else ()
  add_compile_options(-Wa,-mbig-obj)
endif ()