#include <catch2/catch.hpp>
#include <knapsack/BruteForceKnapsackSolver.hpp>

TEST_CASE("Brute-force knapsack problem solving test", "[BruteForceKnapsack]") {
    BruteForceKnapsackSolver<unsigned int, unsigned int> solver;
    solver.solve({});
    REQUIRE(0 == 1);
}