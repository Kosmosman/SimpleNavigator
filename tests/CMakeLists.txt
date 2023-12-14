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

add_executable(tests src/main.cc)

target_link_libraries(tests PRIVATE Graph)

find_package(GTest REQUIRED)
target_link_libraries(tests PRIVATE GTest::gtest_main)

file(COPY res DESTINATION ${CMAKE_BINARY_DIR})

include(GoogleTest)
gtest_discover_tests(tests)