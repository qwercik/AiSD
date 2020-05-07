#include <iostream>
#include <memory>
#include <graphs/Graph.hpp>
#include <graphs/UndirectedAdjacencyListGraph.hpp>

int main() {
	std::unique_ptr<Graph> graph(new UndirectedAdjacencyListGraph(5));
	graph->addEdge(0, 1);
	graph->addEdge(0, 2);
	graph->addEdge(0, 3);
	graph->addEdge(0, 4);
	graph->addEdge(1, 2);
	graph->addEdge(1, 3);
	graph->addEdge(1, 4);
	graph->addEdge(2, 3);
	graph->addEdge(2, 4);
	graph->addEdge(3, 4);
	
	std::cout << *graph;
}
