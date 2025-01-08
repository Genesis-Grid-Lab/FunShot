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
set(CMAKE_C_FLAGS_DEBUG "-g -DDEBUG -msse2")
set(CMAKE_CXX_FLAGS_DEBUG "-g -DDEBUG -msse2")

project(FunShotEngine CXX)

# 1. Set VULKAN_SDK_PATH in .env.cmake to target specific vulkan version
if (DEFINED VULKAN_SDK_PATH)
  set(Vulkan_INCLUDE_DIRS "${VULKAN_SDK_PATH}/Include") # 1.1 Make sure this include path is correct
  set(Vulkan_LIBRARIES "${VULKAN_SDK_PATH}/Lib") # 1.2 Make sure lib path is correct
  set(Vulkan_FOUND "True")
else()
  find_package(Vulkan REQUIRED COMPONENTS glslc shaderc_combined SPIRV-Tools glslang) # throws error if could not find Vulkan
  message(STATUS "Found Vulkan: $ENV{VULKAN_SDK}")
endif()
if (NOT Vulkan_FOUND)
	message(FATAL_ERROR "Could not find Vulkan library!")
else()
	message(STATUS "Using vulkan lib at: ${Vulkan_LIBRARIES}")
endif()

if(${Vulkan_SPIRV-Tools_FOUND})
message(WARNING ${Vulkan_LIBRARIES} "yes" ${VULKAN_SDK} " "
        ${Vulkan_SPIRV-Tools_LIBRARY} ""
        )
else()
message(WARNING ${Vulkan_LIBRARIES} "no" ${VULKAN_SDK_PATH})
endif()

project(FunShotEngine)

add_definitions(-DFS_NO_DLL )

if(WIN32)    
    set(CMAKE_CXX_FLAGS_RELEASE "/wd4996")
    set(CMAKE_CXX_FLAGS_DEBUG "/wd4996")
endif(WIN32)

# enable console logging

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_definitions(-DFS_DEBUG)
endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/glfw)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/glad)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/glm)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/entt)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/imgui)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/spdlog)

set(BOX2D_SAMPLES OFF)
set(BOX2D_UNIT_TESTS OFF)
set(BOX2D_BUILD_DOCS OFF)
set(BOX2D_BUILD_UNIT_TESTS OFF)
set(BOX2D_BUILD_TESTBED OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/box2d)
# set(BUILD_SHARED_LIBS ON)
set(YAML_CPP_BUILD_CONTRIB OFF)
set(YAML_CPP_BUILD_TOOLS OFF)
set(YAML_CPP_BUILD_TESTS OFF)
add_subdirectory(${CMAKE_SOURCE_DIR}/Vendor/yaml-cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/FunShot)
add_subdirectory(${CMAKE_SOURCE_DIR}/FunShotEditor)
# add_subdirectory(SandBox)