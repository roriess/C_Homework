cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

project(homework_4 C)

add_executable(optimal_sorting optimal_sorting.c)
