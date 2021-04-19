add_library(renderer canvas.cxx)

target_include_directories(renderer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/../maths")
target_include_directories(renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(renderer PUBLIC "${CMAKE_SOURCE_DIR}/googletest/googletest/include")