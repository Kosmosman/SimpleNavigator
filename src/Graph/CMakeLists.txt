add_library(Graph STATIC include/Graph/Graph.h src/Graph.cc)

target_include_directories(Graph PUBLIC include)