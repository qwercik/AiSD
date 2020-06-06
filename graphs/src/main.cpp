#include <iostream>
#include <memory>
#include <graphs/graphs.hpp>

void test() {
	int n = 10;
	UndirectedAdjacencyMatrixGraph graph(n);

	UndirectedGraphGenerator gen;
	int edgesNumber = gen.getEdgesNumberFromSaturation(graph, 30);
	gen.fillWithSmallestHamiltonCycle(graph, n);
	gen.fillWithBestMatchedEulerCycle(graph, n, edgesNumber - n);

	HamiltonCycleFind hamiltonFinder(graph);
	EulerCycleFind eulerFinder(graph);

	std::cout << graph;
	std::cout << "Hamilton cycle: " << hamiltonFinder.find() << '\n';
	std::cout << "Euler cycle: " << eulerFinder.find() << '\n';
}

int main() {
	srand(time(nullptr));
	test();
}