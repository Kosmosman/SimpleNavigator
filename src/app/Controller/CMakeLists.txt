CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(Controller)

add_library(s21_controller STATIC
    s21_controller.h
    s21_controller.cc
)
target_include_directories(s21_controller PUBLIC ./)
target_link_libraries(s21_controller PRIVATE s21_model s21_view)
