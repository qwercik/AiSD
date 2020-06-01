#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSorting/Sort.hpp>

class DeepFirstSorting : public Sort {
public:
    std::list<int> sort(DirectedGraph& graph) const;
};