#pragma once

#include <graphs/Graph/Graph.hpp>
#include <graphs/Search/Search.hpp>

class BreadthFirstSearch : public Search {
public:
    virtual std::list<int> search(Graph& graph, int startVertex = 0) const override;
};