add_library(lights pointLight.cxx)

target_include_directories(lights PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(lights PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")