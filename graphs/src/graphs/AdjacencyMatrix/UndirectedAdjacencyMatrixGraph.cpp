#include <iostream>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.hpp>

UndirectedAdjacencyMatrixGraph::UndirectedAdjacencyMatrixGraph(std::size_t verticesNumber) :
    Graph(verticesNumber),
    matrix(verticesNumber, verticesNumber)
{}

void UndirectedAdjacencyMatrixGraph::addEdge(int startVertex, int endVertex) {
    matrix.increment(startVertex, endVertex);
    matrix.increment(endVertex, startVertex);
}

void UndirectedAdjacencyMatrixGraph::removeEdge(int startVertex, int endVertex) {
    matrix.decrement(startVertex, endVertex);
    matrix.decrement(endVertex, startVertex);
}

bool UndirectedAdjacencyMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    // We assumes integrity of adjacency matrix
    return matrix.get(startVertex, endVertex) > 0;
}

void UndirectedAdjacencyMatrixGraph::print(std::ostream& stream) const {
    stream << matrix;
}
