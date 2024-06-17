CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_subdirectory(GraphAlgorithms)
add_subdirectory(includes)
add_subdirectory(Graph)
add_subdirectory(view)

add_executable(SimpleNavigator main.cc)
target_link_libraries(SimpleNavigator s21_graph s21_graph_algorithms s21_view)