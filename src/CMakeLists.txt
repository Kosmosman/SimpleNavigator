CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_subdirectory(algorithms)
add_subdirectory(includes)
add_subdirectory(loader)
add_subdirectory(tests)

add_executable(Tests tests/tests.cc)
target_include_directories(Tests PUBLIC loader)
target_link_libraries(Tests PUBLIC GTest::gtest_main Graph)
