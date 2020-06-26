#include <catch2/catch.hpp>
#include <knapsack/BruteForceKnapsackSolver.hpp>

TEST_CASE("Brute-force knapsack problem solving test 1", "[BruteForceKnapsack]") {
    BruteForceKnapsackSolver<unsigned int, unsigned int> solver;
    auto result = solver.solve(12, {
        {4, 6},
        {3, 5},
        {1, 1},
        {5, 1}
    });

    REQUIRE(result.size() == 3);
    REQUIRE(totalItemsValue<unsigned int>(result.begin(), result.end()) == 12);
}

TEST_CASE("Brute-force knapsack problem solving test 2", "[BruteForceKnapsack]") {
    BruteForceKnapsackSolver<unsigned int, unsigned int> solver;
    auto result = solver.solve(15, {
        {12, 4},
        {2, 2},
        {1, 2},
        {1, 1},
        {4, 10}
    });

    REQUIRE(result.size() == 4);
    REQUIRE(totalItemsValue<unsigned int>(result.begin(), result.end()) == 15);
}

TEST_CASE("Brute-force knapsack problem solving test 3", "[BruteForceKnapsack]") {
    BruteForceKnapsackSolver<unsigned int, unsigned int> solver;
    auto result = solver.solve(112, {
        {4, 49},
        {53, 19},
        {27, 80},
        {3, 40},
        {8, 70},
        {45, 62},
        {20, 37},
        {1, 69},
        {55, 53},
        {21, 17},
        {44, 45},
        {58, 55},
        {26, 78},
        {30, 11},
        {9, 32},
        {21, 40},
        {26, 18},
        {43, 48},
        {47, 11},
        {17, 5}
    });

    REQUIRE(result.size() == 8);
    REQUIRE(totalItemsValue<unsigned int>(result.begin(), result.end()) == 463);
}



