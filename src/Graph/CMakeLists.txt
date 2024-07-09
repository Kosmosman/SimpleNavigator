CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(Graph)

set(LIB_OUTPUT_DIR "${CMAKE_BINARY_DIR}/lib")
file(MAKE_DIRECTORY ${LIB_OUTPUT_DIR})

add_library(s21_graph STATIC
    s21_graph.h

    s21_graph.cc
)

target_compile_options(s21_graph PRIVATE ${COVERAGE_FLAGS})

target_include_directories(s21_graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(s21_graph PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
)

target_link_libraries(s21_graph PRIVATE gcov)