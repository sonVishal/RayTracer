cmake_minimum_required(VERSION 3.10)

# set the project name
project(RayTracer VERSION 0.1)

# for version info
configure_file(src/RayTracerConfig.h.in RayTracerConfig.h)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# for cppcheck
set(CMAKE_CXX_CPPCHECK "cppcheck")

add_subdirectory(src/maths)
add_subdirectory(src/renderer)

# add the executable
add_executable(RayTracer src/main.cxx)

# libraries
target_link_libraries(RayTracer PUBLIC maths renderer)

# include directories
target_include_directories(RayTracer PUBLIC "${PROJECT_BINARY_DIR}")

enable_testing()
include(GoogleTest)
add_subdirectory(tests)