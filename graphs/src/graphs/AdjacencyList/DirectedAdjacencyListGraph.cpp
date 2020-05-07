#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

#include <graphs/Graph.hpp>
#include <graphs/AdjacencyList/DirectedAdjacencyListGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/io.hpp>


DirectedAdjacencyListGraph::DirectedAdjacencyListGraph(std::size_t verticesNumber) :
    Graph(verticesNumber),
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

void DirectedAdjacencyListGraph::print(std::ostream& stream) const {
    for (std::size_t i = 0; i < this->verticesNumber; ++i) {
        stream << "Vertex nr " << i << ": " << lists[i] << '\n';
    }
}
