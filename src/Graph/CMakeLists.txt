CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_library(s21_graph STATIC s21_graph.h s21_graph.cc)

target_include_directories(s21_graph PUBLIC ./)