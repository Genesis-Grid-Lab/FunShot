cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#build output directories
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

project(FunShot)

# enable console logging

if(${CMAKE_BUILD_TYPE} MATCHES Debug)
    add_definitions(-DENABLE_LOG)
endif(${CMAKE_BUILD_TYPE} MATCHES Debug)

set(GLFW_LIBRARY_TYPE "STATIC")

# project subdirectories

add_subdirectory(Vendor/glew/build/cmake)
add_subdirectory(Vendor/glfw)
add_subdirectory(Vendor/spdlog)
add_subdirectory(Vendor/glm)
# add_subdirectory(Vendor/assimp)
add_subdirectory(Vendor/entt)

#gather all source files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_executable(${PROJECT_NAME} ${sources} ${headers})

#export symbols
# target_compile_definitions(${PROJECT_NAME} PUBLIC
#     -DGEN_EXPORT
# )

#include directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/spdlog/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glew/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glm
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/entt/src
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/assimp/include
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/stb
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/RapidJSON/include
    #${CMAKE_CURRENT_SOURCE_DIR}/Vendor/
)

#link directories
target_link_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glfw/src
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/spdlog/src
    ${CMAKE_CURRENT_SOURCE_DIR}/Vendor/glew/src
)

#link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    glew_s
    glfw
    glm
    spdlog
    # assimp
    EnTT
)

# copy resources
if(EXISTS ${CMAKE_SOURCE_DIR}/Resources)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND 
        ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/Resources
        ${EXECUTABLE_OUTPUT_PATH}/Resources
    )
else()
    message(WARNING "[WARNING] no resource directory!")
endif()
