CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(GraphAlgorithms)

add_library(s21_graph_algorithms STATIC
        s21_graph_algorithms.h
        s21_randomizer.h

        s21_graph_algorithms.cc
        s21_randomizer.cc
)
target_include_directories(s21_graph_algorithms PUBLIC ./)

target_link_libraries(s21_graph_algorithms PRIVATE s21_graph Stack Queue)