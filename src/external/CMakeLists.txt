CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_library(Queue INTERFACE s21_queue/s21_queue.h)
target_include_directories(Queue INTERFACE s21_queue)

add_library(Stack INTERFACE s21_stack/s21_stack.h)
target_include_directories(Stack INTERFACE s21_stack)
