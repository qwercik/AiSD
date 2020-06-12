#include <iostream>
#include <string>
#include <cstddef>

#include <graphs/Graph.hpp>
#include <graphs/GraphException.hpp>
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

bool Graph::correctVertex(std::size_t vertex) const {
    return vertex < verticesNumber;
}

void Graph::handleIfVertexNotInRange(std::size_t vertex) const {
    if (!correctVertex(vertex)) {
        throw GraphVertexOutOfRangeException(
            "Vertex " + std::to_string(vertex) + " out of range [0, " + std::to_string(verticesNumber) + ")"
        );
    }
}

void Graph::handleIfEdgeNotExist(std::size_t predecessor, std::size_t successor) const {
    if (!containsEdge(predecessor, successor)) {
        throw GraphEdgeNotExistException(
            "Edge <" + std::to_string(predecessor) + ", " + std::to_string(successor) + "> not exist in graph"
        );
    }
}

std::ostream& operator<<(std::ostream& stream, const Graph& graph) {
    graph.print(stream);
    return stream;
}

