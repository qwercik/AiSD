#include <iostream>
#include <knapsack/knapsack.hpp>

int main() {
    BruteForceKnapsackSolver<unsigned int, unsigned int> bruteSolver;
    bruteSolver.solve(0, {});

    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> dynamicSolver;
    dynamicSolver.solve(0, {});
}