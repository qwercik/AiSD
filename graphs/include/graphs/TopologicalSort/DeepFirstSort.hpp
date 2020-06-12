#pragma once

#include <list>
#include <vector>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/TopologicalSort/Sort.hpp>

class DeepFirstSort : public Sort {
public:
    virtual bool sort(DirectedGraph& graph, std::list<int>& sortingResult) const override;

private:
    enum class VertexColor {
        NOT_VISITED,
        PROCESSING,
        VISITED,
    };

    bool processVertex(const DirectedGraph& graph, int vertex, std::vector<VertexColor>& verticesColors, std::list<int>& sortResult) const;
};