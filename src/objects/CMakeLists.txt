add_library(objects ray.cxx sphere.cxx)

target_include_directories(objects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(objects PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")
target_include_directories(objects PUBLIC "${CMAKE_SOURCE_DIR}/src/materials")