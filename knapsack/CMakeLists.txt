cmake_minimum_required(VERSION 2.8.11)
project(knapsack)

add_executable(benchmark
    src/example/benchmark.cpp
)
target_include_directories(benchmark PUBLIC include/)


add_executable(tests
    src/test/main.cpp
    src/test/BruteForceKnapsackSolver.cpp
    src/test/DynamicProgrammingKnapsackSolver.cpp
)
target_include_directories(tests PUBLIC include/)

