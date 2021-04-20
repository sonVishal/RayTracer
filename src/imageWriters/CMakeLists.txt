add_library(imageWriters imageWriterBase.cxx ppmWriter.cxx)

target_include_directories(imageWriters PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/private")
target_include_directories(imageWriters PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(imageWriters PUBLIC "${CMAKE_SOURCE_DIR}/src/renderer")
target_include_directories(imageWriters PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")
target_include_directories(imageWriters PUBLIC "${CMAKE_SOURCE_DIR}/src/maths/private")