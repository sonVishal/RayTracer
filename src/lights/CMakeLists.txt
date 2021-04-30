file(GLOB LIGHTS_SOURCE_FILES *.cxx)
add_library(lights ${LIGHTS_SOURCE_FILES})

target_include_directories(lights PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(lights PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")