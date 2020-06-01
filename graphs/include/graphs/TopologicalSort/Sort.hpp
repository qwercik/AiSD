#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>

class Sort {
public:
    virtual std::list<int> sort(DirectedGraph& graph) const = 0;
};