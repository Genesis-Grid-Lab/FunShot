project(FunShot)

add_definitions(-DGLFW_INCLUDE_NONE)

# gather all source files
file(GLOB_RECURSE engineFile ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine/*.cpp)
if(WIN32)
    file(GLOB_RECURSE windowFile ${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Windows/*.cpp)
else()
    file(GLOB_RECURSE windowFile )
endif(WIN32)
if(UNIX)
    file(GLOB_RECURSE linuxFile ${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Linux/*.cpp)
else()
    file(GLOB_RECURSE linuxFile )
endif(UNIX)
if(APPLE)
    file(GLOB_RECURSE macFile ${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Mac/*.cpp)
else()
    file(GLOB_RECURSE macFile )
endif()

file(GLOB_RECURSE openGLFile ${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/OpenGL/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)

file(GLOB VulkLib ${CMAKE_SOURCE_DIR}/Vendor/Vulkan/Lib/*.lib)

file(GLOB ImGuizmo ${CMAKE_SOURCE_DIR}/Vendor/ImGuizmo/ImGuizmo.cpp)
file(GLOB ImGuizmoH ${CMAKE_SOURCE_DIR}/Vendor/ImGuizmo/ImGuizmo.h)

add_library(${PROJECT_NAME} ${engineFile} ${windowFile} ${linuxFile} ${macFile} ${openGLFile} ${headers} ${ImGuizmoH} ${CMAKE_SOURCE_DIR}/Vendor/stb/stb_image.cpp ${ImGuizmo} )

target_precompile_headers(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/fspch.h)

# includes directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Engine
    ${CMAKE_SOURCE_DIR}/Vendor/assimp/include
    ${CMAKE_SOURCE_DIR}/Vendor/entt/src/entt
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
    ${CMAKE_SOURCE_DIR}/Vendor/ImGuizmo
    ${CMAKE_SOURCE_DIR}/Vendor/imgui/backends
    ${CMAKE_SOURCE_DIR}/Vendor/box2d/include
    ${Vulkan_INCLUDE_DIRS}
)


# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC     
    glad
    glfw
    glm
    spdlog
    imgui
    EnTT 
    ${Vulkan_LIBRARIES}  
    ${VulkLib}     
    yaml-cpp
    box2d
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