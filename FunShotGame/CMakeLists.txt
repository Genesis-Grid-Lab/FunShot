project(Game)

# gather all source files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_executable(${PROJECT_NAME} ${sources} ${CMAKE_SOURCE_DIR}/FunShotEditor/src/EditorLayer.cpp  ${headers})

# export engine symbols
target_compile_definitions(${PROJECT_NAME} PUBLIC 
)

# includes directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/Editor
    ${CMAKE_SOURCE_DIR}/FunShotEngine/include
    ${CMAKE_SOURCE_DIR}/FunShotEditor/include
    ${CMAKE_SOURCE_DIR}/FunShotEditor/include/Editor
)

# link directories
target_link_directories(${PROJECT_NAME} PUBLIC 
)

# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    FunShotEngine
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