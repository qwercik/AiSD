#pragma once

#include <list>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/TopologicalSort/TopologicalSort.hpp>

class TopologicalBreadthFirstSort : public TopologicalSort {
public:
    virtual std::list<int> sort(DirectedGraph& graph) const override;
};