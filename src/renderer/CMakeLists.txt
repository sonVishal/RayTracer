add_library(renderer canvas.cxx)

target_include_directories(renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(renderer PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")