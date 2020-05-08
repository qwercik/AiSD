#include <iostream>
#include <cstddef>

#include <graphs/Graph.hpp>
#include <graphs/io.hpp>

Graph::Graph(std::size_t verticesNumber) {
    this->verticesNumber = verticesNumber;
}

void Graph::print(std::ostream& stream) const {
    for (int i = 0; i < verticesNumber; ++i) {
        stream << "[" << i << "]: " << getAdjacentVertices(i) << '\n';
    }
}

std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
    graph.print(stream);
    return stream;
}

