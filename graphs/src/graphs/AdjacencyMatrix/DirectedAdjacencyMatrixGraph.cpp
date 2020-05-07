#include <iostream>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.hpp>

DirectedAdjacencyMatrixGraph::DirectedAdjacencyMatrixGraph(std::size_t verticesNumber) :
    Graph(verticesNumber),
    matrix(verticesNumber, verticesNumber)
{}

void DirectedAdjacencyMatrixGraph::addEdge(int startVertex, int endVertex) {
    matrix.increment(startVertex, endVertex);
}

void DirectedAdjacencyMatrixGraph::removeEdge(int startVertex, int endVertex) {
    matrix.decrement(startVertex, endVertex);
}

bool DirectedAdjacencyMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    return matrix.get(startVertex, endVertex) > 0;
}

void DirectedAdjacencyMatrixGraph::print(std::ostream& stream) const {
    stream << matrix;
}
