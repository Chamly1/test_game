cmake_minimum_required(VERSION 3.24)
project(test_game)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

add_executable(test_game)
target_link_libraries(test_game main)
