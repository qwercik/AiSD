#pragma once

#include <list>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/TopologicalSort/Sort.hpp>

class BreadthFirstSort : public Sort {
public:
    virtual bool sort(DirectedGraph& graph, std::list<int>& sortingResult) const override;
};