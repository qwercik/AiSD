#pragma once

#include <knapsack/KnapsackSolver.hpp>

class BruteForceKnapsackSolver : public KnapsackSolver {
public:
    virtual void solve() const override;
};