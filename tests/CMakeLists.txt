add_subdirectory("${PROJECT_SOURCE_DIR}/googletest" "googletest")

macro(package_add_test TESTNAME)
    # create an exectuable in which the tests will be stored
    add_executable(${TESTNAME} ${ARGN})
    # add include paths
    target_include_directories(${TESTNAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/maths")
    target_include_directories(${TESTNAME} PUBLIC "${CMAKE_SOURCE_DIR}/src/renderer")
    # link the Google test infrastructure, mocking library, and a default main fuction to
    # the test executable.  Remove g_test_main if writing your own main function.
    target_link_libraries(${TESTNAME} gtest gmock gtest_main maths renderer)
    gtest_discover_tests(${TESTNAME}
        # set a working directory so your project root so that you can find test data via paths relative to the project root
        WORKING_DIRECTORY ${PROJECT_DIR}
        PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
    )
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

package_add_test(test_vector4 test_vector4.cxx)
package_add_test(test_point4 test_point4.cxx)
package_add_test(test_colour test_colour.cxx)
package_add_test(test_canvas test_canvas.cxx)