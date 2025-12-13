cmake_minimum_required(VERSION 3.25)

project(homework_6 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

add_executable(countingRhyme countingRhyme.c)
add_executable(sortedList sortedList.c)

add_library(operationsForList operationsForList.c)
add_library(operationsForSortedList operationsForSortedList.c)

target_link_libraries(countingRhyme PRIVATE operationsForList)
target_link_libraries(sortedList PRIVATE operationsForSortedList)
