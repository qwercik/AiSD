#pragma once

#include <list>

#include <graphs/Graph.hpp>

class Search {
public:
    virtual std::list<int> search(Graph& graph, int startVertex = 0) const = 0;
};