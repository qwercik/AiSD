#pragma once

#include <vector>
#include <list>

#include <graphs/Graph.hpp>
#include <graphs/Search/Search.hpp>

class DeepFirstSearch : public Search {
public:
    virtual std::list<int> search(Graph& graph, int startVertex = 0) const override;

private:
    void searchBackend(Graph& graph, int currentVertex, std::vector<bool>& visitedVertices, std::list<int>& searchResult) const;
};