#include <iostream>
#include <list>

#include <graphs/UndirectedGraph.hpp>
#include <graphs/Matrix/GrowableMatrix.hpp>
#include <graphs/IncidenceMatrix/UndirectedIncidenceMatrixGraph.hpp>

UndirectedIncidenceMatrixGraph::UndirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
    UndirectedGraph(verticesNumber),
    matrix(0, verticesNumber)
{}

void UndirectedIncidenceMatrixGraph::addEdge(int startVertex, int endVertex) {
    matrix.addRow();
    auto edgeIndex = matrix.getRows() - 1;

    matrix.set(edgeIndex, startVertex, 1);
    matrix.set(edgeIndex, endVertex, 1);
}

void UndirectedIncidenceMatrixGraph::removeEdge(int startVertex, int endVertex) {
    auto edgeIndex = findEdgeRow(startVertex, endVertex);
    matrix.removeRow(edgeIndex);
}

bool UndirectedIncidenceMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    return findEdgeRow(startVertex, endVertex) != -1;
}

std::list<int> UndirectedIncidenceMatrixGraph::getAdjacentVertices(int vertex) const {
    std::list<int> vertices;
    for (int i = 0; i < matrix.getRows(); ++i) {
        if (matrix.get(i, vertex) == 1) {
            int incidentVertex = 0;
            while (matrix.get(i, incidentVertex) != 1 || incidentVertex == vertex) {
                incidentVertex++;
            }

            vertices.push_back(incidentVertex);
        }
    }

    return vertices;
}

int UndirectedIncidenceMatrixGraph::findEdgeRow(int startVertex, int endVertex) const {
    for (int row = 0; row < matrix.getRows(); ++row) {
        if (matrix.get(row, startVertex) == 1 && matrix.get(row, endVertex) == 1) {
            return row;
        }
    }

    // If not find
    return -1;
}