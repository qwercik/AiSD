#include <iostream>
#include <list>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/GrowableMatrix.hpp>
#include <graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.hpp>

DirectedIncidenceMatrixGraph::DirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
    Graph(verticesNumber),
    matrix(0, verticesNumber)
{}

void DirectedIncidenceMatrixGraph::addEdge(int startVertex, int endVertex) {
    matrix.addRow();
    auto edgeIndex = matrix.getRows() - 1;

    matrix.set(edgeIndex, startVertex, 1);
    matrix.set(edgeIndex, endVertex, -1);
}

void DirectedIncidenceMatrixGraph::removeEdge(int startVertex, int endVertex) {
    auto edgeIndex = findEdgeRow(startVertex, endVertex);
    matrix.removeRow(edgeIndex);
}

bool DirectedIncidenceMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    return findEdgeRow(startVertex, endVertex) != -1;
}

std::list<int> DirectedIncidenceMatrixGraph::getAdjacentVertices(int vertex) const {
    std::list<int> vertices;
    for (int i = 0; i < matrix.getRows(); ++i) {
        if (matrix.get(i, vertex) == 1) {
            int incidentVertex = 0;
            while (matrix.get(i, incidentVertex) != -1) {
                incidentVertex++;
            }

            vertices.push_back(incidentVertex);
        }
    }

    return vertices;
}

int DirectedIncidenceMatrixGraph::findEdgeRow(int startVertex, int endVertex) const {
    for (int row = 0; row < matrix.getRows(); ++row) {
        if (matrix.get(row, startVertex) == 1 && matrix.get(row, endVertex) == -1) {
            return row;
        }
    }

    // If not find
    return -1;
}
