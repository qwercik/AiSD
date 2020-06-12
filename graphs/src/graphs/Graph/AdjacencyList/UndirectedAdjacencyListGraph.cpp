#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/Graph/GraphException.hpp>
#include <graphs/Graph/AdjacencyList/UndirectedAdjacencyListGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/io.hpp>

UndirectedAdjacencyListGraph::UndirectedAdjacencyListGraph(std::size_t verticesNumber) :
    UndirectedGraph(verticesNumber),
    lists(verticesNumber, std::list<int>())
{}

void UndirectedAdjacencyListGraph::addEdge(int startVertex, int endVertex) {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    lists[startVertex].push_back(endVertex);
    lists[endVertex].push_back(startVertex);
}

void UndirectedAdjacencyListGraph::removeEdge(int startVertex, int endVertex) {
    handleIfEdgeNotExist(startVertex, endVertex);

    lists[startVertex].remove(endVertex);
    lists[endVertex].remove(startVertex);
}

bool UndirectedAdjacencyListGraph::containsEdge(int startVertex, int endVertex) const {
    handleIfVertexNotInRange(startVertex);
    handleIfVertexNotInRange(endVertex);

    // We assumes integrity of lists
    auto current = lists[startVertex];
    return std::find(current.begin(), current.end(), endVertex) != current.end();
}

std::list<int> UndirectedAdjacencyListGraph::getSuccessors(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return lists[vertex];
}

std::list<int> UndirectedAdjacencyListGraph::getPredecessors(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return lists[vertex];
}

std::size_t UndirectedAdjacencyListGraph::getIndegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return lists[vertex].size();
}

std::size_t UndirectedAdjacencyListGraph::getOutdegree(int vertex) const {
    handleIfVertexNotInRange(vertex);
    return lists[vertex].size();
}

void UndirectedAdjacencyListGraph::dedicatedPrint(std::ostream& stream) const {
    print(stream);
}
