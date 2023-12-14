CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(Tests ${CMAKE_SOURCE_DIR}/src/tests/tests.cc)
target_include_directories(Tests PUBLIC ${CMAKE_SOURCE_DIR}/src/loader)
target_link_libraries(Tests PUBLIC GTest::gtest_main Graph)