project(View)

add_library(s21_view STATIC
    s21_view.h

    s21_view.cc
)
target_include_directories(s21_view PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR})