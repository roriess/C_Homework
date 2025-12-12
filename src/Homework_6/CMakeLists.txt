cmake_minimum_required(VERSION 3.25)

project(homework_6 C)

add_executable(countingRhyme countingRhyme.c)
add_executable(sortedList sortedList.c)

add_library(operationsForList operationsForList.c)
add_library(operationsForSortedList operationsForSortedList.c)

target_link_directories(countingRhyme PRIVATE .)
target_link_directories(sortedList PRIVATE .)

target_link_libraries(countingRhyme PRIVATE operationsForList)
target_link_libraries(sortedList PRIVATE operationsForSortedList)
