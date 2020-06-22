#pragma once

#include <knapsack/KnapsackSolver.hpp>

class DynamicProgrammingKnapsackSolver : public KnapsackSolver {
public:
    virtual void solve() const override;
};