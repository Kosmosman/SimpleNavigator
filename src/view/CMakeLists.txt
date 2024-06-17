CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_library(s21_view STATIC s21_view.h s21_view.cc)
target_link_libraries(s21_view PRIVATE s21_graph_algorithms)

target_include_directories(s21_view PUBLIC ./)