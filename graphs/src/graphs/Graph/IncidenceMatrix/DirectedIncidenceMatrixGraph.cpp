#include <iostream>
#include <list>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/Graph/IncidenceMatrix/DirectedIncidenceMatrixGraph.hpp>
#include <graphs/io.hpp>

DirectedIncidenceMatrixGraph::DirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
    DirectedGraph(verticesNumber)
{}

void DirectedIncidenceMatrixGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    matrix.push_back(std::vector<int>(verticesNumber, 0));
    matrix.back()[startVertex] = 1;
    matrix.back()[endVertex] = -1;
}

void DirectedIncidenceMatrixGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);

    auto edgeIterator = findEdgeRow(startVertex, endVertex);
    matrix.erase(edgeIterator);
}

bool DirectedIncidenceMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    return findEdgeRow(startVertex, endVertex) != matrix.end();
}

std::list<int> DirectedIncidenceMatrixGraph::getSuccessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::list<int> successors;
    for (const auto& edge : matrix) {
        if (edge[vertex] == 1) {
            int successor = 0;
            while (edge[successor] != -1) {
                successor++;
            }

            successors.push_back(successor);
        }
    }

    return successors;
}

std::list<int> DirectedIncidenceMatrixGraph::getPredecessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::list<int> predecessors;
    for (const auto& edge : matrix) {
        if (edge[vertex] == -1) {
            int predecessor = 0;
            while (edge[predecessor] != 1) {
                predecessor++;
            }

            predecessors.push_back(predecessor);
        }
    }

    return predecessors;
}

std::size_t DirectedIncidenceMatrixGraph::getIndegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    std::size_t counter = 0;

    for (const auto& edge : matrix) {
        if (edge[vertex] == -1) {
            counter++;
        }
    }

    return counter;
}

std::size_t DirectedIncidenceMatrixGraph::getOutdegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    std::size_t counter = 0;

    for (const auto& edge : matrix) {
        if (edge[vertex] == 1) {
            counter++;
        }
    }

    return counter;
}

DirectedIncidenceMatrixGraph::IncidenceMatrix::const_iterator DirectedIncidenceMatrixGraph::findEdgeRow(int startVertex, int endVertex) const {
    auto iterator = matrix.begin();
    
    for (; iterator != matrix.end(); ++iterator) {
        auto& row = *iterator;
        if (row[startVertex] == 1 && row[endVertex] == -1) {
            break;
        }
    }

    return iterator;
}

void DirectedIncidenceMatrixGraph::dedicatedPrint(std::ostream& stream) const {
    for (const auto& row : matrix) {
        stream << row << '\n';
    }
}