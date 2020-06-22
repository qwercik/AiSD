#pragma once

#include <list>
#include <vector>
#include <knapsack/KnapsackSolver.hpp>
#include <knapsack/Item.hpp>

template <typename Weight, typename Value>
class DynamicProgrammingKnapsackSolver : public KnapsackSolver<Weight, Value> {
public:
    virtual std::list<Item<Weight, Value>> solve(Weight capacity, const std::vector<Item<Weight, Value>>& items) const override {
        return {};
    }
};