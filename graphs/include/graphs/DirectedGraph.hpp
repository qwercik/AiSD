#pragma once

#include <graphs/Graph.hpp>

class DirectedGraph : public Graph {
public:
    using Graph::Graph;

    std::size_t maxEdges() const override {
        auto vertices = getVerticesNumber();
        return vertices * (vertices - 1);
    }
};
