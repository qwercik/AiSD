#include <iostream>

#include <graphs/DirectedGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.hpp>

DirectedAdjacencyMatrixGraph::DirectedAdjacencyMatrixGraph(std::size_t verticesNumber) :
    DirectedGraph(verticesNumber),
    matrix(verticesNumber, verticesNumber)
{}

void DirectedAdjacencyMatrixGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);
    matrix.increment(startVertex, endVertex);
}

void DirectedAdjacencyMatrixGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);
    matrix.decrement(startVertex, endVertex);
}

bool DirectedAdjacencyMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);
    return matrix.get(startVertex, endVertex) > 0;
}

std::list<int> DirectedAdjacencyMatrixGraph::getSuccessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::list<int> vertices;
    for (int i = 0; i < verticesNumber; ++i) {
        auto count = matrix.get(vertex, i);
        for (int j = 0; j < count; ++j) {
            vertices.push_back(i);
        }
    }

    return vertices;
}

std::list<int> DirectedAdjacencyMatrixGraph::getPredecessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::list<int> vertices;
    for (int i = 0; i < verticesNumber; ++i) {
        auto count = matrix.get(i, vertex);
        for (int j = 0; j < count; ++j) {
            vertices.push_back(i);
        }
    }

    return vertices;
}

std::size_t DirectedAdjacencyMatrixGraph::getIndegree(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::size_t counter = 0;
    for (int current = 0; current < verticesNumber; ++current) {
        counter += matrix.get(current, vertex);
    }

    return counter;
}

std::size_t DirectedAdjacencyMatrixGraph::getOutdegree(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::size_t counter = 0;
    for (int current = 0; current < verticesNumber; ++current) {
        counter += matrix.get(vertex, current);
    }

    return counter;
}

void DirectedAdjacencyMatrixGraph::dedicatedPrint(std::ostream& stream) const {
    stream << matrix;
}
