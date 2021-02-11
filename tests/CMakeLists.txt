# cmake .. && cmake --build . && ./9_UnitTesting/bin/UnitTestingProject_unit_tests

set(TEST_SOURCES "main.cpp")
 
# add the executabl, it's in same dir
# The variable TEST_MAIN is set in the root CMake
add_executable(${TEST_MAIN} ${TEST_SOURCES})
# Settings: Module dirrectory from where code to be unittested are stored 
target_link_libraries(${TEST_MAIN} PRIVATE 
                                    ${CONAN_CATCH2} 
                                    ${LIBRARY_SRC} 
                                    ${LIBRARY_ADD}
                                    ${LIBRARY_MUL}
                                    ${LIBRARY_SQR}
                                    ${LIBRARY_SUB}
                                    )
target_compile_features(${TEST_MAIN} PUBLIC cxx_std_17)
# Test hinzufügen
add_test(NAME ${LIBRARY_SRC}.${TEST_MAIN} COMMAND ${TEST_MAIN})
# Covegare
if(ENABLE_COVERAGE)
    set(COVERAGE_MAIN           "${PROJECT}_coverage")
    # hier wird gesetzt welche projkte ignoriert werden muss
    # don't needs to be build
    set(COVERAGE_LCOV_EXCLUDES
    "${PROJECT_SOURCE_DIR}/apps/*"
    "${PROJECT_SOURCE_DIR}/cmake/*"
    "${PROJECT_SOURCE_DIR}/docs/*"
    "${PROJECT_SOURCE_DIR}/tests/*"
    "${PROJECT_SOURCE_DIR}/tests/*"
    "${PROJECT_SOURCE_DIR}/external/*"
    "${CONAN_BOOST_ROOT}/*"
    "${CONAN_CATCH2_ROOT}/*"
    "${CONAN_CELERO_ROOT}/*"
    "${CONAN_CXXOPTS_ROOT}/*"
    "/usr/include/*")
    # code coverage bericht
    setup_target_for_coverage_lcov(
        NAME ${COVERAGE_MAIN}
        EXECUTABLE ctest
        DEPENDENCIES ${TEST_MAIN} )

endif()