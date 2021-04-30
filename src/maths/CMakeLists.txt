file(GLOB MATHS_SOURCE_FILES *.cxx)
add_library(maths ${MATHS_SOURCE_FILES})

target_include_directories(maths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})