#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include <graphs/Graph.hpp>
#include <graphs/AdjacencyList/UndirectedAdjacencyListGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/io.hpp>

UndirectedAdjacencyListGraph::UndirectedAdjacencyListGraph(std::size_t verticesNumber) :
    Graph(verticesNumber),
    lists(verticesNumber, std::list<int>())
{}

void UndirectedAdjacencyListGraph::addEdge(int startVertex, int endVertex) {
    lists[startVertex].push_back(endVertex);
    lists[endVertex].push_back(startVertex);
}

void UndirectedAdjacencyListGraph::removeEdge(int startVertex, int endVertex) {
    lists[startVertex].remove(endVertex);
    lists[endVertex].remove(startVertex);
}

bool UndirectedAdjacencyListGraph::containsEdge(int startVertex, int endVertex) const {
    // We assumes integrity of lists
    auto current = lists[startVertex];
    return std::find(current.begin(), current.end(), endVertex) != current.end();
}

std::list<int> UndirectedAdjacencyListGraph::getAdjacentVertices(int vertex) const {
    return lists[vertex];
}