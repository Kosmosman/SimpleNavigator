CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

enable_testing()

option(ENABLE_COVERAGE "Enable coverage instrumentation" OFF)
if(ENABLE_COVERAGE)
    set(COVERAGE_FLAGS -fprofile-arcs -ftest-coverage -fPIC -O0 -g --coverage)
else()
    set(COVERAGE_FLAGS "")
endif()

add_subdirectory(external)
add_subdirectory(Graph)
add_subdirectory(GraphAlgorithms)
add_subdirectory(tests)
add_subdirectory(SimpleNavigator)