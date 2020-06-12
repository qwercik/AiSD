#include <iostream>

#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/Graph/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.hpp>

UndirectedAdjacencyMatrixGraph::UndirectedAdjacencyMatrixGraph(std::size_t verticesNumber) :
    UndirectedGraph(verticesNumber),
    matrix(verticesNumber, verticesNumber)
{}

void UndirectedAdjacencyMatrixGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    matrix.increment(startVertex, endVertex);
    matrix.increment(endVertex, startVertex);
}

void UndirectedAdjacencyMatrixGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);

    matrix.decrement(startVertex, endVertex);
    matrix.decrement(endVertex, startVertex);
}

bool UndirectedAdjacencyMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    // We assumes integrity of adjacency matrix
    return matrix.get(startVertex, endVertex) > 0;
}

std::list<int> UndirectedAdjacencyMatrixGraph::getSuccessors(int vertex) const {
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

std::list<int> UndirectedAdjacencyMatrixGraph::getPredecessors(int vertex) const {
    // We assumes integrity of adjacency matrix
    // For unordered graph list of successors and predecessors should be the same
    handleIfVertexNotInRange(vertex);
    return getSuccessors(vertex);
}

std::size_t UndirectedAdjacencyMatrixGraph::getIndegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return getOutdegree(vertex);
}

std::size_t UndirectedAdjacencyMatrixGraph::getOutdegree(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::size_t counter = 0;
    for (int current = 0; current < verticesNumber; ++current) {
        counter += matrix.get(current, vertex);
    }

    return counter;
}

void UndirectedAdjacencyMatrixGraph::dedicatedPrint(std::ostream& stream) const {
    stream << matrix;
}
