#pragma once

#include <cstddef>

class Graph {
public:
    Graph(std::size_t verticesNumber) {
        this->verticesNumber = verticesNumber;
    }

    virtual void addEdge(int startVertex, int endVertex) = 0;
    virtual void removeEdge(int startVertex, int endVertex) = 0;

    virtual bool containsEdge(int startVertex, int endVertex) const = 0;

    virtual void print(std::ostream& stream) const = 0;

protected:
    std::size_t verticesNumber;
};

std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
    graph.print(stream);
    return stream;
}

