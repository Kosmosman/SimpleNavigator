CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(Model)

add_library(s21_model STATIC
    s21_model.h
    s21_model.cc
)
target_include_directories(s21_model PUBLIC ./)
target_link_libraries(s21_model PRIVATE s21_graph_algorithms s21_graph)

