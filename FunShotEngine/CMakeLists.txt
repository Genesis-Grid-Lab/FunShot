project(Engine)

# gather all source files
file(GLOB_RECURSE sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB_RECURSE headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
add_library(${PROJECT_NAME} SHARED ${sources} ${headers})

# export engine symbols
target_compile_definitions(${PROJECT_NAME} PUBLIC 
    -DGEN_EXPORT
)

# includes directories
target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/includes
    ${CONAN_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/Vendor/assimp/include
    ${CMAKE_SOURCE_DIR}/Vendor/entt/src
    ${CMAKE_SOURCE_DIR}/Vendor/glew/include
    ${CMAKE_SOURCE_DIR}/Vendor/glfw/include
    ${CMAKE_SOURCE_DIR}/Vendor/glm
    ${CMAKE_SOURCE_DIR}/Vendor/stb
    ${CMAKE_SOURCE_DIR}/Vendor/spdlog/include
    ${CMAKE_SOURCE_DIR}/Vendor/magic_enum/include
    ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/include
    ${CMAKE_SOURCE_DIR}/Vendor/PhysX/pxshared/include
    ${CMAKE_SOURCE_DIR}/Vendor/yaml-cpp
    ${CMAKE_SOURCE_DIR}/Vendor/lua
    ${CMAKE_SOURCE_DIR}/Vendor/sol2/include
)

# link directories
target_link_directories(${PROJECT_NAME} PUBLIC 
    ${CONAN_LIB_DIRS}  
)

if(WIN32)
    if(CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        message("Building snippet in debug configuration")
        add_compile_definitions(_DEBUG)
        link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/debug") # This is the path where PhysX libraries are installed
    else()
        message("Building snippet in release configuration with PhysX ${PHYSX_BUILD_TYPE} configuration")
        add_compile_definitions(NDEBUG)
        link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/${PHYSX_BUILD_TYPE}") # This is the path where PhysX libraries are installed
    endif()
else()
    if(CMAKE_BUILD_TYPE AND CMAKE_BUILD_TYPE STREQUAL "Debug")
        message("Building snippet in debug configuration")
        add_compile_definitions(_DEBUG)
        link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.mt/debug") # This is the path where PhysX libraries are installed
    else()
        message("Building snippet in release configuration with PhysX ${PHYSX_BUILD_TYPE} configuration")
        add_compile_definitions(NDEBUG)
        link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/${PHYSX_BUILD_TYPE}") # This is the path where PhysX libraries are installed
    endif()
endif()

# link libraries
target_link_libraries(${PROJECT_NAME} PUBLIC
    ${CONAN_LIBS}    
    glew_s
    glfw
    glm
    spdlog
    assimp
    EnTT 
    magic_enum
    yaml-cpp
    lua
    sol2
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXExtensions_static_64.lib        
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysX_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXPvdSDK_static_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXCommon_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/PhysXFoundation_64.lib
    )
else()
    target_link_libraries(${PROJECT_NAME} PUBLIC
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/debug/PhysXExtensions_static_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/debug/PhysX_static_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/debug/PhysXPvdSDK_static_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/debug/PhysXCommon_static_64.lib
        ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/linux.clang/debug/PhysXFoundation_static_64.lib
    )
endif()

# copy .dll files
if (MSVC)
    foreach(directory ${CONAN_BIN_DIRS})
        file(GLOB dllfiles ${directory}/*.dll)
        foreach(dllfile ${dllfiles})
            if (EXISTS ${dllfile})
                add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
                    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                    ${dllfile} ${EXECUTABLE_OUTPUT_PATH})
            endif()
        endforeach()
    endforeach()

    file(GLOB physxdlls ${CMAKE_SOURCE_DIR}/Vendor/PhysX/physx/bin/win.x86_64.vc142.md/debug/*.dll)
    foreach(physxdll ${physxdlls})
        if (EXISTS ${physxdll})
            add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD 
                COMMAND ${CMAKE_COMMAND} -E copy_if_different 
                ${physxdll} ${EXECUTABLE_OUTPUT_PATH})
        endif()
    endforeach()
endif(MSVC)

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

# copy script directory
if(EXISTS ${CMAKE_SOURCE_DIR}/FunShotScript)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD COMMAND 
        ${CMAKE_COMMAND} -E copy_directory 
        ${CMAKE_SOURCE_DIR}/FunShotScript
        ${EXECUTABLE_OUTPUT_PATH}/Resources/Scripts
    )
else()
    message(WARNING "[WARNING] no script directory!")
endif()
