project(FunShot)

add_definitions(-DGLFW_INCLUDE_NONE)

# gather all source files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
add_library(${PROJECT_NAME} ${sources} ${headers} ${CMAKE_SOURCE_DIR}/Vendor/stb/stb_image.cpp )

target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/fspch.h)

# includes directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine
    ${CMAKE_SOURCE_DIR}/Vendor/assimp/include
    ${CMAKE_SOURCE_DIR}/Vendor/entt/src
    ${CMAKE_SOURCE_DIR}/Vendor/glad/include
    ${CMAKE_SOURCE_DIR}/Vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/Vendor/glm
    ${CMAKE_SOURCE_DIR}/Vendor/stb
    ${CMAKE_SOURCE_DIR}/Vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/Vendor/magic_enum/include
    ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/include
    ${CMAKE_SOURCE_DIR}/Vendor/PhysX/pxshared/include
    ${CMAKE_SOURCE_DIR}/Vendor/yaml-cpp
    ${CMAKE_SOURCE_DIR}/Vendor/imgui
    ${CMAKE_SOURCE_DIR}/Vendor/imgui/backends
    ${CMAKE_SOURCE_DIR}/Vendor/sol2/include
)


# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC     
    glad
    glfw
    glm
    spdlog
    imgui
    # EnTT 
    # magic_enum
    # yaml-cpp
    # lua
    # sol2
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