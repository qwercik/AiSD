#include <iostream>
#include <cstddef>

#include <graphs/Graph.hpp>

Graph::Graph(std::size_t verticesNumber) {
    this->verticesNumber = verticesNumber;
}

std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
    graph.print(stream);
    return stream;
}

