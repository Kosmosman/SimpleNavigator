cmake_minimum_required(VERSION 3.11)

# include(FetchContent)

# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        release-1.12.0
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) 
# FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests src/main.cc
        src/shortest_way_test.cc
        src/shortest_way_all_vertexes.cc)

find_package(GTest REQUIRED)
target_link_libraries(tests PRIVATE s21_graph s21_graph_algorithms GTest::gtest_main)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

add_test(NAME tests COMMAND tests)