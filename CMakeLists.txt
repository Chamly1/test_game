cmake_minimum_required(VERSION 3.24)
project(test_game)

set(CMAKE_CXX_STANDARD 17)

message(*************************************)
message(${CMAKE_CXX_COMPILER_ID})
message(*************************************)

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/external/SFML-2.5.1")
set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML COMPONENTS system window graphics network audio main)
#If you're linking the static version of SFML, SFML's header files have to know about this (since the function
#signature changes slightly). As such you'll have to define SFML_STATIC somewhere before you include any SFML header,
#ideally as part of your project, make files, or build system.
add_compile_definitions(SFML_STATIC)

#######################################################

include_directories("${CMAKE_SOURCE_DIR}/external/SFML-2.5.1/include")
include_directories("${CMAKE_SOURCE_DIR}/include")

add_subdirectory(src/GameEngine)
add_subdirectory(src/Game)

add_executable(test_game)
target_link_libraries(test_game PUBLIC game_engine_objlib game_objlib)
target_link_libraries(test_game PUBLIC sfml-system sfml-window sfml-graphics sfml-network sfml-audio sfml-main)

# copy resources
add_custom_command(TARGET test_game
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources)
