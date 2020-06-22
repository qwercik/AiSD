#include <iostream>
#include <knapsack/knapsack.hpp>

int main() {
    BruteForceKnapsackSolver bruteSolver;
    bruteSolver.solve();

    DynamicProgrammingKnapsackSolver dynamicSolver;
    dynamicSolver.solve();
}