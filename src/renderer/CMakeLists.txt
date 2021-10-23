file(GLOB RENDERER_SOURCE_FILES *.cxx)
add_library(renderer ${RENDERER_SOURCE_FILES})

target_include_directories(renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(renderer PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")
target_include_directories(renderer PUBLIC "${CMAKE_SOURCE_DIR}/src/lights")
target_include_directories(renderer PUBLIC "${CMAKE_SOURCE_DIR}/src/materials")
target_include_directories(renderer PUBLIC "${CMAKE_SOURCE_DIR}/src/objects")