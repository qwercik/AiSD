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

std::list<int> DirectedAdjacencyListGraph::getAdjacentVertices(int vertex) const {
    return lists[vertex];
}