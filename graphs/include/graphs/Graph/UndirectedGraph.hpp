#pragma once

#include <graphs/Graph/Graph.hpp>

class UndirectedGraph : public Graph {
public:
    using Graph::Graph;

    virtual std::size_t maxEdges() const override {
        auto vertices = getVerticesNumber();
        return vertices * (vertices - 1) / 2;
    }

    virtual std::size_t totalEdges() const override {
        std::size_t sumOfDegrees = 0;
        for (int i = 0; i < getVerticesNumber(); ++i) {
            sumOfDegrees += getDegree(i);
        }

        return sumOfDegrees / 2;
    }

    std::size_t getDegree(int vertex) const  {
        // We assume integrity of graph
        // In this case degree == outdegree == indegree
        return getOutdegree(vertex);
    }
};
