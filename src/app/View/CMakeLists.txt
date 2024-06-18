CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(View)

add_library(s21_view STATIC
    s21_view.h

    s21_view.cc
)
target_include_directories(s21_view PUBLIC ./)