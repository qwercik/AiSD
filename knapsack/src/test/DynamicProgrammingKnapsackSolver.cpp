#include <catch2/catch.hpp>
#include <knapsack/DynamicProgrammingKnapsackSolver.hpp>

TEST_CASE("Dynamic programming knapsack problem solving test", "[DynamicProgrammingKnapsack]") {
    DynamicProgrammingKnapsackSolver<unsigned int, unsigned int> solver;
    solver.solve({});
    REQUIRE(0 == 1);
}