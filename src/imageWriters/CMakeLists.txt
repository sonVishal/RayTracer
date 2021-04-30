file(GLOB IMAGE_WRITERS_SOURCE_FILES *.cxx)
add_library(imageWriters ${IMAGE_WRITERS_SOURCE_FILES})

target_include_directories(imageWriters PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_include_directories(imageWriters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(imageWriters PUBLIC "${CMAKE_SOURCE_DIR}/src/renderer")
target_include_directories(imageWriters PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")