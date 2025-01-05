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

if(WIN32)
    add_definitions(-DFS_PLATFORM_WINDOW)
endif(WIN32)

add_definitions(-DFS_NO_DLL)

if(WIN32)    
    set(CMAKE_CXX_FLAGS_RELEASE "/wd4996")
    set(CMAKE_CXX_FLAGS_DEBUG "/wd4996")
endif(WIN32)

# enable console logging

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_definitions(-DFS_DEBUG)
endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

add_subdirectory(Vendor/glfw)
add_subdirectory(Vendor/glad)
add_subdirectory(Vendor/glm)
add_subdirectory(Vendor/entt)
add_subdirectory(Vendor/imgui)
add_subdirectory(Vendor/spdlog)
# add_subdirectory(Vendor/magic_enum)
# add_subdirectory(Vendor/lua)
# add_subdirectory(Vendor/sol2)
# set(BUILD_SHARED_LIBS ON)
set(YAML_CPP_BUILD_CONTRIB OFF)
set(YAML_CPP_BUILD_TOOLS OFF)
add_subdirectory(Vendor/yaml-cpp)

add_subdirectory(Funshot)
add_subdirectory(FunshotEditor)
# add_subdirectory(SandBox)