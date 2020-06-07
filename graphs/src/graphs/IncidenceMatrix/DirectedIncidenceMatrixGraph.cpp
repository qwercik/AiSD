#include <iostream>
#include <list>

#include <graphs/DirectedGraph.hpp>
#include <graphs/Matrix/GrowableMatrix.hpp>
#include <graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.hpp>

DirectedIncidenceMatrixGraph::DirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
    DirectedGraph(verticesNumber),
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

std::list<int> DirectedIncidenceMatrixGraph::getSuccessors(int vertex) const {
    std::list<int> successors;
    for (int i = 0; i < matrix.getRows(); ++i) {
        if (matrix.get(i, vertex) == 1) {
            int successor = 0;
            while (matrix.get(i, successor) != -1) {
                successor++;
            }

            successors.push_back(successor);
        }
    }

    return successors;
}

std::list<int> DirectedIncidenceMatrixGraph::getPredecessors(int vertex) const {
    std::list<int> predecessors;
    for (int i = 0; i < matrix.getRows(); ++i) {
        if (matrix.get(i, vertex) == -1) {
            int predecessor = 0;
            while (matrix.get(i, predecessor) != 1) {
                predecessor++;
            }

            predecessors.push_back(predecessor);
        }
    }

    return predecessors;
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

void DirectedIncidenceMatrixGraph::dedicatedPrint(std::ostream& stream) const {
    stream << matrix;
}