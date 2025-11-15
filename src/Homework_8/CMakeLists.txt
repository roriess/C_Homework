cmake_minimum_required(VERSION 3.25)
project(advancedBalanceOfBrackets C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -pedantic")

add_library(implementationOfStack ${PROJECT_SOURCE_DIR}/implementationOfStack.c)
add_library(checkingForASymbol ${PROJECT_SOURCE_DIR}/shuntingYard/checkingForASymbol.c)

target_include_directories(implementationOfStack PUBLIC ${PROJECT_SOURCE_DIR}/implementationOfStack.h)
target_include_directories(checkingForASymbol PUBLIC ${PROJECT_SOURCE_DIR}/shuntingYard/checkingForASymbol.h)

add_executable(advancedBalanceOfBrackets ${PROJECT_SOURCE_DIR}/advancedBalanceOfBrackets/advancedBalanceOfBrackets.c)
add_executable(shuntingYard ${PROJECT_SOURCE_DIR}/shuntingYard/shuntingYard.c)

target_link_libraries(advancedBalanceOfBrackets PRIVATE implementationOfStack)
target_link_libraries(shuntingYard PRIVATE implementationOfStack checkingForASymbol)