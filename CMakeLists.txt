########### main CMakeLists.txt  ###########
# Build: cmake -D USE_PRINTF=ON ..
cmake_minimum_required(VERSION 3.14)

set(PROJECT "CppTemplate")

project("${PROJECT}_Project" VERSION 1.2.3 LANGUAGES CXX)

# Global CMake variables are set here
set(CMAKE_CXX_STANDARD          17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS        OFF)

# target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)

# Options : value of the option is stored in the cache
option(ENABLE_BENCHMARKING    "Enable a Code Coverage buid."   ON)
option(ENABLE_TESTING       "Enable a Unit Testing buid."    ON)
option(ENABLE_COVERAGE      "Enable a code covegare buid."   ON)
 
  
# Cmake modules Doxygen
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(Documentation)

# Inclute CTest when enable Testing option
if (ENABLE_TESTING)
    message("Unit-testing is enabled")
    include(CTest)
else(ENABLE_TESTING)
    message("Unit-testing method NOT enabled")
endif()
# Inclute CodeCoverage from cmake dir  when enable coverage option 
if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        include(CodeCoverage)
    else()
        message("Coverage only for GNU|Clang")
        set (ENABLE_COVERAGE OFF)
    endif()
endif()

# set allias: Project/library name
set(LIBRARY_LINALG      "${PROJECT}_Linalg")
set(LIBRARY_LOGURU      "${PROJECT}_loguru")
set(LIBRARY_ADD 	    "${PROJECT}_Add")
set(LIBRARY_SUB 	    "${PROJECT}_Sub")
set(LIBRARY_MUL 	    "${PROJECT}_Mul")
set(LIBRARY_SQR 	    "${PROJECT}_Sqr")
set(LIBRARY_SRC         "${PROJECT}_Src")
set(MAIN                "${PROJECT}_Executable")
set(TEST_MAIN           "${PROJECT}_unit_tests")
set(COVERAGE_MAIN       "${PROJECT}_coverage")
set(BENCHMARK_MAIN      "${PROJECT}_benchmarks")

# Add conan externe library
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()
# External lib
add_subdirectory("${PROJECT_SOURCE_DIR}/external/")
# Add applications libraries
add_subdirectory("${PROJECT_SOURCE_DIR}/add/")
add_subdirectory("${PROJECT_SOURCE_DIR}/sub/")
add_subdirectory("${PROJECT_SOURCE_DIR}/mul/")
add_subdirectory("${PROJECT_SOURCE_DIR}/src/") 
add_subdirectory("${PROJECT_SOURCE_DIR}/square/")
add_subdirectory("${PROJECT_SOURCE_DIR}/apps/")

# Add tests and coverage folder, enabling testing
if (ENABLE_TESTING OR ENABLE_COVERAGE)
    # Aktivieren CTest paket 
    enable_testing() 
    message("Unit-testing methon enable_testing() is enabled")
    add_subdirectory("${PROJECT_SOURCE_DIR}/tests/")
else(ENABLE_TESTING )
    message("Unit-testing method NOT enabled")
endif()

# Add benchmarks
#add_subdirectory("${PROJECT_SOURCE_DIR}/benchmarks/")
if(ENABLE_BENCHMARKING)
    message("Benchmarks is enabled")
    add_subdirectory("${PROJECT_SOURCE_DIR}/benchmarks/")
endif()

