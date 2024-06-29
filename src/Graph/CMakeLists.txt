CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(Graph)

add_library(s21_graph STATIC
    s21_graph.h

    s21_graph.cc
)

target_include_directories(s21_graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
