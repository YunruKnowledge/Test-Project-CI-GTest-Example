cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
add_compile_options(-Wall -Wextra -Wpedantic)

project(Dynamic_queue_test)

add_executable(run_test test/test.cpp)
target_link_libraries(run_test PRIVATE gtest gmock gtest_main)
target_include_directories(run_test PRIVATE lib/queue test)

enable_testing()
add_test(NAME REQUIREMENT_TEST COMMAND run_test)