project(Model)
add_library(s21_model STATIC
    s21_model.h
    s21_model.cc
)
target_include_directories(s21_model PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(s21_model PRIVATE s21_graph_algorithms s21_graph)
