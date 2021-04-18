add_library(maths tuple4.cxx vector4.cxx point4.cxx)

target_include_directories(maths PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_include_directories(maths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(maths PUBLIC "${CMAKE_SOURCE_DIR}/googletest/googletest/include")