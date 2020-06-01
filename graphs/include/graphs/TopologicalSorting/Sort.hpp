#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>

class Sort {
public:
    virtual std::list<int> sort(const DirectedGraph& graph) const = 0;
};