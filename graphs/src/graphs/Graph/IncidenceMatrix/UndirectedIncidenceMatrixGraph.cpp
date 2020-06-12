#include <iostream>
#include <list>

#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/Matrix/GrowableMatrix.hpp>
#include <graphs/Graph/IncidenceMatrix/UndirectedIncidenceMatrixGraph.hpp>

UndirectedIncidenceMatrixGraph::UndirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
    UndirectedGraph(verticesNumber),
    matrix(0, verticesNumber)
{}

void UndirectedIncidenceMatrixGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    matrix.addRow();
    auto edgeIndex = matrix.getRows() - 1;

    matrix.set(edgeIndex, startVertex, 1);
    matrix.set(edgeIndex, endVertex, 1);
}

void UndirectedIncidenceMatrixGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);

    auto edgeIndex = findEdgeRow(startVertex, endVertex);
    matrix.removeRow(edgeIndex);
}

bool UndirectedIncidenceMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    return findEdgeRow(startVertex, endVertex) != -1;
}

std::list<int> UndirectedIncidenceMatrixGraph::getSuccessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

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

std::list<int> UndirectedIncidenceMatrixGraph::getPredecessors(int vertex) const {
    // Successors and predecessors should be the same
    handleIfVertexNotInRange(vertex);
    return getSuccessors(vertex);
}

std::size_t UndirectedIncidenceMatrixGraph::getIndegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return getOutdegree(vertex);
}

std::size_t UndirectedIncidenceMatrixGraph::getOutdegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    std::size_t counter = 0;

    for (int edge = 0; edge < matrix.getRows(); ++edge) {
        if (matrix.get(edge, vertex) == 1) {
            counter++;
        }
    }

    return counter;
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

void UndirectedIncidenceMatrixGraph::dedicatedPrint(std::ostream& stream) const {
    stream << matrix;
}