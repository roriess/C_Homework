cmake_minimum_required(VERSION 3.25)
project(task1 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c11")

add_library(operationsTask1 ${PROJECT_SOURCE_DIR}/operationsTask1.c)
add_library(testsTask1 ${PROJECT_SOURCE_DIR}/testsTask1.c)

target_include_directories(operationsTask1 PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(task1 ${PROJECT_SOURCE_DIR}/task1.c)

target_link_libraries(task1 PRIVATE operationsTask1 testsTask1)