#pragma once

#include <vector>
#include <list>
#include <knapsack/Item.hpp>

template <typename Weight, typename Value>
class KnapsackSolver {
public:
    virtual std::list<Item<Weight, Value>> solve(const std::vector<Item<Weight, Value>>& items) const = 0;
};