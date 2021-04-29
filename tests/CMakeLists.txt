add_subdirectory("${PROJECT_SOURCE_DIR}/googletest" "googletest")

macro(package_add_test TESTNAME FILENAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${FILENAME})
    # add include paths
    # link the Google test infrastructure, mocking library, and a default main fuction to
    # the test executable.  Remove g_test_main if writing your own main function.
    foreach(loop_var ${ARGN})
        target_include_directories(${TESTNAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/${loop_var}")
        target_link_libraries(${TESTNAME} ${loop_var})
    endforeach()
    target_link_libraries(${TESTNAME} gtest gmock gtest_main)
    gtest_discover_tests(${TESTNAME}
        # set a working directory so your project root so that you can find test data via paths relative to the project root
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(test_vector4 test_vector4.cxx maths)
package_add_test(test_point4 test_point4.cxx maths)
package_add_test(test_colour test_colour.cxx maths)
package_add_test(test_matrix test_matrix.cxx maths)
package_add_test(test_transform test_transform.cxx maths)
package_add_test(test_ray test_ray.cxx maths objects)
package_add_test(test_sphere test_sphere.cxx maths objects materials)
package_add_test(test_canvas test_canvas.cxx maths renderer)
package_add_test(test_ppmWriter test_ppmWriter.cxx maths renderer imageWriters)
package_add_test(test_light test_light.cxx maths lights objects materials)
package_add_test(test_material test_material.cxx maths materials)
package_add_test(test_shader test_shader.cxx maths materials renderer lights)