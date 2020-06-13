#pragma once

#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/io.hpp>

class HamiltonianCycleFind : public CycleFind {
public:
    HamiltonianCycleFind(UndirectedGraph& graph);
    virtual std::list<int> find() override;

private:
    /**
     * Returns true if Hamiltonian cycle has been already found
     * Otherwise returns false
     */
    bool findNextCycle();

    const int START_VERTEX = 0;
    UndirectedGraph& graph;
    std::vector<bool> visited;
    std::list<int> path;
    std::list<std::list<int>> successors;
    int currentVertex;
};