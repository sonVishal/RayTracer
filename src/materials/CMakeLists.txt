add_library(materials material.cxx)

target_include_directories(materials PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(materials PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")