#pragma once

#include <list>

#include <graphs/Graph.hpp>

class BreadthFirstSorting {
public:
    std::list<int> sort(Graph& graph) const;
};