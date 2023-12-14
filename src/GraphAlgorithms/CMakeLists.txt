CMAKE_MINIMUM_REQUIRED(VERSION 3.15)
PROJECT(SimpleNavigator)
SET(CMAKE_CXX_STANDARD 17)

add_library(GraphAlgorithms STATIC include/GraphAlgorithms/GraphAlgorithms.h src/GraphAlgorithms.cc)

target_include_directories(GraphAlgorithms PUBLIC include)