project(Controller)

add_library(s21_controller STATIC
    s21_controller.h
    s21_controller.cc
)
target_include_directories(s21_controller PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(s21_controller PRIVATE s21_model s21_view)
