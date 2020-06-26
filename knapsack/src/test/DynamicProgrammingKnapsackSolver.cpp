#include <catch2/catch.hpp>
#include <knapsack/DynamicProgrammingKnapsackSolver.hpp>
#include <io.hpp>

TEST_CASE("Dynamic programming knapsack problem solving test 1", "[DynamicProgrammingKnapsack]") {
    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> solver;
    auto result = solver.solve(12, {
        {4, 6},
        {3, 5},
        {1, 1},
        {5, 1}
    });

    REQUIRE(result.size() == 3);
    REQUIRE(totalItemsValue<unsigned int>(result.begin(), result.end()) == 12);
}

TEST_CASE("Dynamic programming knapsack problem solving test 2", "[DynamicProgrammingKnapsack]") {
    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> solver;
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

TEST_CASE("Dynamic programming knapsack problem solving test 3", "[DynamicProgrammingKnapsack]") {
    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> solver;
    auto result = solver.solve(7, {
        {1, 1},
        {3, 4},
        {4, 5},
        {5, 7}
    });

    REQUIRE(result.size() == 2);
    REQUIRE(totalItemsValue<unsigned int>(result.begin(), result.end()) == 9);
}

TEST_CASE("Dynamic programming knapsack problem solving test 4", "[DynamicProgrammingKnapsack]") {
    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> solver;
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