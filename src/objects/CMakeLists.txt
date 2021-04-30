file(GLOB OBJECTS_SOURCE_FILES *.cxx)
add_library(objects ${OBJECTS_SOURCE_FILES})

target_include_directories(objects PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(objects PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")
target_include_directories(objects PUBLIC "${CMAKE_SOURCE_DIR}/src/materials")