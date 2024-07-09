CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(GraphAlgorithms)

set(LIB_OUTPUT_DIR "${CMAKE_BINARY_DIR}/lib")
file(MAKE_DIRECTORY ${LIB_OUTPUT_DIR})

add_library(s21_graph_algorithms STATIC
        s21_graph_algorithms.h

        s21_graph_algorithms.cc
)

target_compile_options(s21_graph_algorithms PRIVATE ${COVERAGE_FLAGS})

target_include_directories(s21_graph_algorithms PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(s21_graph_algorithms PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
    ARCHIVE_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
    RUNTIME_OUTPUT_DIRECTORY ${LIB_OUTPUT_DIR}
)

target_link_libraries(s21_graph_algorithms PRIVATE s21_graph Stack Queue gcov)