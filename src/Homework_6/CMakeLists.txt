cmake_minimum_required(VERSION 3.25)

project(homework9 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c11")

add_library(operationsForSortedList ${PROJECT_SOURCE_DIR}/operationsForSortedList.c)
add_library(testsForSortedList ${PROJECT_SOURCE_DIR}/testsForSortedList.c)

target_include_directories(operationsForSortedList PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(sortedList ${PROJECT_SOURCE_DIR}/sortedList.c)

target_link_libraries(sortedList PRIVATE operationsForSortedList testsForSortedList)