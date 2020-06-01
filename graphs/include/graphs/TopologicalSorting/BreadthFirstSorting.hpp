#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSorting/Sort.hpp>

class BreadthFirstSorting : public Sort {
public:
    std::list<int> sort(DirectedGraph& graph) const;
};