#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>

class BreadthFirstSorting {
public:
    std::list<int> sort(DirectedGraph& graph) const;
};