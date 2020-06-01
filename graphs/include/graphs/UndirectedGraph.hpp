#pragma once

#include <graphs/Graph.hpp>

class UndirectedGraph : public Graph {
public:
    using Graph::Graph;

    virtual std::size_t maxEdges() const override {
        auto vertices = getVerticesNumber();
        return vertices * (vertices - 1) / 2;
    }
};
