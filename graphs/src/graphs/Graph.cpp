#include <iostream>
#include <cstddef>

#include <graphs/Graph.hpp>
#include <graphs/io.hpp>

Graph::Graph(std::size_t verticesNumber) {
    this->verticesNumber = verticesNumber;
}

std::size_t Graph::getVerticesNumber() const {
    return this->verticesNumber;
}

bool Graph::isComplete() const {
    return totalEdges() == maxEdges();
}

void Graph::print(std::ostream& stream) const {
    for (int i = 0; i < verticesNumber; ++i) {
        stream << "[" << i << "]: " << getSuccessors(i) << '\n';
    }
}

std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
    graph.print(stream);
    return stream;
}

