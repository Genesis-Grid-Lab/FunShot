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


add_subdirectory(Vendor/raylib)
add_subdirectory(Vendor/spdlog)
add_subdirectory(Vendor/imgui)
add_subdirectory(Vendor/raylib-cpp)
add_subdirectory(Vendor/rImGui)
add_subdirectory(Vendor/entt)


# project subdirectories
add_subdirectory(FunShotEngine)
add_subdirectory(FunShotEditor)
add_subdirectory(FunShotGame)
