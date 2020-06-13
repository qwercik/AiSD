#include <iostream>
#include <list>

#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/Graph/IncidenceMatrix/UndirectedIncidenceMatrixGraph.hpp>
#include <graphs/io.hpp>

UndirectedIncidenceMatrixGraph::UndirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
    UndirectedGraph(verticesNumber)
{}

void UndirectedIncidenceMatrixGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    matrix.push_back(std::vector<int>(verticesNumber, 0));
    matrix.back()[startVertex] = 1;
    matrix.back()[endVertex] = 1;
}

void UndirectedIncidenceMatrixGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);

    auto edgeIterator = findEdgeRow(startVertex, endVertex);
    matrix.erase(edgeIterator);
}

bool UndirectedIncidenceMatrixGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    return findEdgeRow(startVertex, endVertex) != matrix.end();
}

std::list<int> UndirectedIncidenceMatrixGraph::getSuccessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::list<int> vertices;
    for (const auto& edge : matrix) {
        if (edge[vertex] == 1) {
            int incidentVertex = 0;
            while (edge[incidentVertex] != 1 || incidentVertex == vertex) {
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

    for (const auto& edge : matrix) {
        if (edge[vertex] == 1) {
            counter++;
        }
    }

    return counter;
}

UndirectedIncidenceMatrixGraph::IncidenceMatrix::const_iterator UndirectedIncidenceMatrixGraph::findEdgeRow(int startVertex, int endVertex) const {
    auto iterator = matrix.begin();
    for (; iterator != matrix.end(); ++iterator) {
        const auto& edge = *iterator;
        if (edge[startVertex] == 1 && edge[endVertex] == 1) {
            break;
        }
    }

    return iterator;
}

void UndirectedIncidenceMatrixGraph::dedicatedPrint(std::ostream& stream) const {
    for (const auto& edge : matrix) {
        stream << edge << '\n';
    }
}