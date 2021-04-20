add_library(maths tuple4.cxx vector4.cxx point4.cxx colour.cxx matrix4x4.cxx)

target_include_directories(maths PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_include_directories(maths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})