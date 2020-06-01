#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSort/Sort.hpp>

class BreadthFirstSort : public Sort {
public:
    virtual std::list<int> sort(DirectedGraph& graph) const override;
};