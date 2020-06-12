#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include <graphs/DirectedGraph.hpp>
#include <graphs/AdjacencyList/DirectedAdjacencyListGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/io.hpp>


DirectedAdjacencyListGraph::DirectedAdjacencyListGraph(std::size_t verticesNumber) :
    DirectedGraph(verticesNumber),
    lists(verticesNumber, std::list<int>())
{}

void DirectedAdjacencyListGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    lists[startVertex].push_back(endVertex);
}

void DirectedAdjacencyListGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);
    lists[startVertex].remove(endVertex);
}

bool DirectedAdjacencyListGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    auto current = lists[startVertex];
    return std::find(current.begin(), current.end(), endVertex) != current.end();
}

std::list<int> DirectedAdjacencyListGraph::getSuccessors(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return lists[vertex];
}

std::list<int> DirectedAdjacencyListGraph::getPredecessors(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::list<int> predecessorsList;
    int current = 0;
    for (const auto& vertexSuccessors : lists) {
        for (auto successor : vertexSuccessors) {
            if (successor == vertex) {
                predecessorsList.push_back(current);
            }
        }

        current++;
    }

    return predecessorsList;
}

std::size_t DirectedAdjacencyListGraph::getIndegree(int vertex) const {
    handleIfVertexNotInRange(vertex);

    std::size_t counter = 0;
    for (const auto& list : lists) {
        for (auto successor : list) {
            if (successor == vertex) {
                counter++;
            }
        }
    }

    return counter;
}

std::size_t DirectedAdjacencyListGraph::getOutdegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return lists[vertex].size();
}

void DirectedAdjacencyListGraph::dedicatedPrint(std::ostream& stream) const {
    print(stream);
}
