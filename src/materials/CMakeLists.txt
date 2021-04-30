file(GLOB MATERIALS_SOURCE_FILES *.cxx)
add_library(materials ${MATERIALS_SOURCE_FILES})

target_include_directories(materials PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(materials PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")