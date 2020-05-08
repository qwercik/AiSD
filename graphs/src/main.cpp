#include <iostream>
#include <memory>
#include <graphs/Graph.hpp>
#include <graphs/AdjacencyMatrix/DirectedAdjacencyMatrixGraph.hpp>
#include <graphs/AdjacencyMatrix/UndirectedAdjacencyMatrixGraph.hpp>
#include <graphs/AdjacencyList/DirectedAdjacencyListGraph.hpp>
#include <graphs/AdjacencyList/UndirectedAdjacencyListGraph.hpp>
#include <graphs/IncidenceMatrix/DirectedIncidenceMatrixGraph.hpp>
#include <graphs/IncidenceMatrix/UndirectedIncidenceMatrixGraph.hpp>
#include <graphs/Search/Search.hpp>
#include <graphs/Search/DeepFirstSearch.hpp>
#include <graphs/Search/BreadthFirstSearch.hpp>
#include <graphs/Generator/Generator.hpp>

int main() {
	UndirectedIncidenceMatrixGraph graph(10);
	graph.addEdge(0, 1);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);
	graph.addEdge(3, 5);
	graph.addEdge(3, 6);
	graph.addEdge(4, 7);
	graph.addEdge(8, 9);
	graph.addEdge(4, 8);
	std::cout << graph;

	BreadthFirstSearch bfs;
	std::cout << "BFS: " << bfs.search(graph) << '\n';

	DeepFirstSearch dfs;
	std::cout << "DFS: " << dfs.search(graph) << '\n';
}
