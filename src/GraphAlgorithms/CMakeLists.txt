CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_library(s21_graph_algorithms STATIC s21_graph_algorithms.h s21_graph_algorithms.cc
        s21_randomizer.cc
        s21_randomizer.h)
target_link_libraries(s21_graph_algorithms PRIVATE s21_graph Stack Queue)

target_include_directories(s21_graph_algorithms PUBLIC ./)