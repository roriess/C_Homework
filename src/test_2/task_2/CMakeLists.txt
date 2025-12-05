cmake_minimum_required(VERSION 3.25)
project(task2 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c11")

add_library(operationsTask2 ${PROJECT_SOURCE_DIR}/operationsTask2.c)
add_library(testsTask2 ${PROJECT_SOURCE_DIR}/testsTask2.c)

target_include_directories(operationsTask2 PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(task1 ${PROJECT_SOURCE_DIR}/task2.c)

target_link_libraries(task2 PRIVATE operationsTask2 testsTask2)