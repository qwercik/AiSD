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
    lists[startVertex].push_back(endVertex);
}

void DirectedAdjacencyListGraph::removeEdge(int startVertex, int endVertex) {
    lists[startVertex].remove(endVertex);
}

bool DirectedAdjacencyListGraph::containsEdge(int startVertex, int endVertex) const {
    auto current = lists[startVertex];
    return std::find(current.begin(), current.end(), endVertex) != current.end();
}

std::list<int> DirectedAdjacencyListGraph::getSuccessors(int vertex) const {
    return lists[vertex];
}

std::list<int> DirectedAdjacencyListGraph::getPredecessors(int vertex) const {
    std::list<int> predecessorsList;
    for (int i = 0; i < lists.size(); ++i) {
        auto vertexSuccessors = lists[i];
        auto iterator = std::find(vertexSuccessors.begin(), vertexSuccessors.end(), vertex);
        if (iterator != vertexSuccessors.end()) {
            predecessorsList.push_back(vertex);
        }
    }

    return predecessorsList;
}