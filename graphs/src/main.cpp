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
#include <graphs/TopologicalSort/BreadthFirstSort.hpp>
#include <graphs/TopologicalSort/DeepFirstSort.hpp>
#include <graphs/Generator/Generator.hpp>

void test1() {
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

void test2() {
	DirectedAdjacencyMatrixGraph graph(6);
	graph.addEdge(0, 2);
	graph.addEdge(1, 0);
	graph.addEdge(1, 2);
	graph.addEdge(3, 0);
	graph.addEdge(3, 1);
	graph.addEdge(3, 4);
	graph.addEdge(4, 1);
	graph.addEdge(4, 2);
	graph.addEdge(5, 0);
	graph.addEdge(5, 4);

	std::cout << graph;

	// Pamiętać, że sortowanie może modyfikować graf!!!
	std::cout << (new DeepFirstSort)->sort(graph) << '\n';
	std::cout << (new BreadthFirstSort)->sort(graph) << '\n';
}

void test3() {
	DirectedAdjacencyMatrixGraph graph(12);
	graph.addEdge(7, 11);
	graph.addEdge(7, 8);
	graph.addEdge(5, 11);
	graph.addEdge(3, 8);
	graph.addEdge(3, 10);
	graph.addEdge(8, 9);
	graph.addEdge(11, 2);
	graph.addEdge(11, 9);
	graph.addEdge(11, 10);

	std::cout << graph;

	// Pamiętać, że sortowanie może modyfikować graf!!!
	std::cout << (new DeepFirstSort)->sort(graph) << '\n';
	std::cout << (new BreadthFirstSort)->sort(graph) << '\n';
}

void test4() {
	Generator generator;
	auto graph = generator.generate<DirectedIncidenceMatrixGraph>(10, 100);
	std::cout << graph;
}

int main() {
	test4();
}
