#pragma once

#include <list>
#include <vector>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSort/Sort.hpp>

class DeepFirstSort : public Sort {
public:
    virtual std::list<int> sort(DirectedGraph& graph) const override;

private:
    void processVertex(const DirectedGraph& graph, int vertex, std::vector<bool>& visitedVertices, std::list<int>& sortResult) const;
};