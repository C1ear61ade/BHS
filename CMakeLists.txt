cmake_minimum_required(VERSION 4.2)
project(BlackholeSim)

target_include_directories(BlackholeSim PRIVATE ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)

add_executable(BlackholeSim main.cpp
        Math/Vector3.h
        Math/Vector3.cpp
        Math/Tensor.h
        Math/Tensor.cpp
        Math/Matrix4.h
        Math/Matrix4.cpp
        Physics/CelestialBodies.cpp
        Physics/CelestialBodies.h
        Renderings/OpenGL.cpp)
