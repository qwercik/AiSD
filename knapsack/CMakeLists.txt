cmake_minimum_required(VERSION 2.8.11)
project(knapsack)

add_executable(example
    src/example/main.cpp
)
target_include_directories(example PUBLIC include/)


add_executable(tests
    src/test/main.cpp
    src/test/BruteForceKnapsackSolver.cpp
    src/test/DynamicProgrammingKnapsackSolver.cpp
)
target_include_directories(tests PUBLIC include/)

