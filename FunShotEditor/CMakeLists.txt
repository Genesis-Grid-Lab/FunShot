project(Editor)

# gather all source files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h)
add_executable(${PROJECT_NAME} ${sources} ${headers})

# includes directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/FunShot/src
    ${CMAKE_SOURCE_DIR}/FunShot/src/Engine
    ${CMAKE_SOURCE_DIR}/Vendor/glm
    ${CMAKE_SOURCE_DIR}/Vendor/imgui
    ${CMAKE_SOURCE_DIR}/Vendor/ImGuizmo
)

# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC     
    FunShot    
)