#pragma once

#include <list>

#include <graphs/Graph/DirectedGraph.hpp>

class Sort {
public:
    virtual bool sort(DirectedGraph& graph, std::list<int>& sortingResult) const = 0;
};