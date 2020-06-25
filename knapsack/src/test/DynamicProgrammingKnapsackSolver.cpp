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

    std::cerr << "[DBG] ";
    for (const auto& item : result) {
        std::cerr << "[" << item.first << ", "  << item.second << "] ";
    }
    std::cerr << '\n';

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

    std::cerr << "[DBG] ";
    for (const auto& item : result) {
        std::cerr << "[" << item.first << ", "  << item.second << "] ";
    }
    std::cerr << '\n';

    REQUIRE(result.size() == 4);
    REQUIRE(totalItemsValue<unsigned int>(result.begin(), result.end()) == 15);
    REQUIRE(totalItemsWeight<unsigned int>(result.begin(), result.end()) == 8);
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
    REQUIRE(totalItemsWeight<unsigned int>(result.begin(), result.end()) == 7);
}