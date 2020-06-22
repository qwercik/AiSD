#include <iostream>
#include <knapsack/knapsack.hpp>

int main() {
    BruteForceKnapsackSolver<unsigned int, unsigned int> bruteSolver;
    bruteSolver.solve({});

    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> dynamicSolver;
    dynamicSolver.solve({});
}