CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
SET(CMAKE_CXX_STANDARD 17)

PROJECT(SimpleNavigator)

add_subdirectory(Model)
add_subdirectory(View)
add_subdirectory(Controller)

add_executable(SimpleNavigator main.cc)
target_link_libraries(SimpleNavigator PRIVATE s21_controller s21_model s21_view)
