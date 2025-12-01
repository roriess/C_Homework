cmake_minimum_required(VERSION 3.25)
project(homework10 C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic -std=c11")

add_library(operationsForDoubleNum ${PROJECT_SOURCE_DIR}/operationsForDoubleNum.c)
add_library(testsForDoubleUnderMicroscope ${PROJECT_SOURCE_DIR}/testsForDoubleUnderMicroscope.c)

target_include_directories(operationsForDoubleNum PUBLIC ${PROJECT_SOURCE_DIR})

add_executable(doubleUnderMicroscope ${PROJECT_SOURCE_DIR}/doubleUnderMicroscope.c)

target_link_libraries(doubleUnderMicroscope PRIVATE operationsForDoubleNum testsForDoubleUnderMicroscope)