# Set minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(002)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add main.cpp as an executable target
add_executable(${PROJECT_NAME} main.cpp)

# Include headers from 3D_Objects & Geometry /headers directories
include_directories(libraries/3D_Objects/headers)
include_directories(libraries/Geometry/headers)

# Add source files from 3D_Objects & Geometry /src directories
file(GLOB SOURCES libraries/3D_Objects/src/*.cpp)
file(GLOB SOURCES libraries/Geometry/src/*.cpp)

# Add source files to the executable target
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
