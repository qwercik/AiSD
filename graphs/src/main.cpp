#include <iostream>
#include <memory>
#include <graphs/Graph.hpp>
#include <graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.hpp>
#include <graphs/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.hpp>
#include <graphs/AdjacencyList/DirectedAdjacencyListGraph.hpp>
#include <graphs/AdjacencyList/UndirectedAdjacencyListGraph.hpp>
#include <graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.hpp>
#include <graphs/IncidenceMatrix/UndirectedIncidenceMatrixGraph.hpp>

int main() {
	std::unique_ptr<Graph> graph(new UndirectedIncidenceMatrixGraph(7));
	
	graph->addEdge(1, 2);
	graph->addEdge(1, 4);
	graph->addEdge(2, 3);
	graph->addEdge(2, 4);
	graph->addEdge(3, 5);
	graph->addEdge(3, 6);
	graph->addEdge(6, 5);

	std::cout << *graph;
}
