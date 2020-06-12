#pragma once

#include <graphs/Graph.hpp>

class DirectedGraph : public Graph {
public:
    using Graph::Graph;

    virtual std::size_t maxEdges() const override {
        auto vertices = getVerticesNumber();
        return vertices * (vertices - 1);
    }

    virtual std::size_t totalEdges() const override {
        std::size_t sumOfDegrees = 0;
        for (int i = 0; i < getVerticesNumber(); ++i) {
            sumOfDegrees += getOutdegree(i);
        }

        return sumOfDegrees;
    }
};
