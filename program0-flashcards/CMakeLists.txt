cmake_minimum_required(VERSION 3.26)
project(flashcards)
set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -pedantic)

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp src/app.cpp src/card.cpp)
set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")