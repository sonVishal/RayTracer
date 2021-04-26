cmake_minimum_required(VERSION 3.10)

# for using MSVC runtime library flags
cmake_policy(SET CMP0091 NEW)

# forces a statically-linked runtime library
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# set the project name
project(RayTracer VERSION 0.2)

# for version info
configure_file(src/RayTracerConfig.h.in RayTracerConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# for cppcheck
set(CMAKE_CXX_CPPCHECK "cppcheck")

add_subdirectory(src/maths)
add_subdirectory(src/renderer)
add_subdirectory(src/imageWriters)
add_subdirectory(src/objects)
add_subdirectory(src/materials)

# add the executable
add_executable(RayTracer src/main.cxx)

# libraries
target_link_libraries(RayTracer PUBLIC objects renderer imageWriters maths)

# include directories
target_include_directories(RayTracer PUBLIC "${PROJECT_BINARY_DIR}")

enable_testing()
include(GoogleTest)
add_subdirectory(tests)