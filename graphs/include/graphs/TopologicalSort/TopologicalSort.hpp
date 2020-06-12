#pragma once

#include <list>

#include <graphs/Graph/DirectedGraph.hpp>

class TopologicalSort {
public:
    virtual std::list<int> sort(DirectedGraph& graph) const = 0;
};