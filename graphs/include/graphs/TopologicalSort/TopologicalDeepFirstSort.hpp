#pragma once

#include <list>
#include <vector>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/TopologicalSort/TopologicalSort.hpp>

class TopologicalDeepFirstSort : public TopologicalSort {
public:
    virtual std::list<int> sort(DirectedGraph& graph) const override;

private:
    enum class VertexColor {
        NOT_VISITED,
        PROCESSING,
        VISITED,
    };

    bool processVertex(const DirectedGraph& graph, int vertex, std::vector<VertexColor>& verticesColors, std::list<int>& sortResult) const;
};