cmake_minimum_required(VERSION 2.8.11)
project(knapsack)


add_library(knapsack
    include/knapsack/KnapsackSolver.hpp

    include/knapsack/BruteForceKnapsackSolver.hpp
    src/knapsack/BruteForceKnapsackSolver.cpp

    include/knapsack/DynamicProgrammingKnapsackSolver.hpp
    src/knapsack/DynamicProgrammingKnapsackSolver.cpp
)
target_include_directories(knapsack PUBLIC include/)



add_executable(example
    src/example/main.cpp
)
target_include_directories(example PUBLIC include/)
target_link_libraries(example PUBLIC knapsack)


add_executable(tests
    src/test/main.cpp
    src/test/BruteForceKnapsackSolver.cpp
    src/test/DynamicProgrammingKnapsackSolver.cpp
)
target_include_directories(tests PUBLIC include/)
target_link_libraries(tests PUBLIC knapsack)

