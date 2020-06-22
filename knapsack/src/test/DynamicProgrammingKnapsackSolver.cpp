#include <catch2/catch.hpp>
#include <knapsack/DynamicProgrammingKnapsackSolver.hpp>

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
    REQUIRE(totalItemsWeight<unsigned int>(result.begin(), result.end()) == 12);
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
    REQUIRE(totalItemsWeight<unsigned int>(result.begin(), result.end()) == 8);
}