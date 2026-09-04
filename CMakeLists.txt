cmake_minimum_required(VERSION 3.20)

project(BlackholeSim)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)

set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(glfw)

find_package(OpenGL REQUIRED)

set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/Externals/imgui)

set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp

        ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

add_executable(BlackholeSim

        main.cpp
        Math/Vector3.cpp
        Math/Matrix4.cpp
        Math/Tensor.cpp
        Physics/CelestialBodies.cpp
        Graphics/Rendering.cpp
        Graphics/Camera.cpp

        ${IMGUI_SOURCES}
        Graphics/GUI-initiator.h
)

target_include_directories(BlackholeSim PRIVATE

        ${CMAKE_SOURCE_DIR}

        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
)

target_link_libraries(BlackholeSim PRIVATE

        glfw
        OpenGL::GL
)