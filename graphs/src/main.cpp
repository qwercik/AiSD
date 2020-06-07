#include <iostream>
#include <memory>
#include <graphs/graphs.hpp>

void test() {
	UndirectedGraphGenerator gen;
	auto graph = gen.generateBothEulerAndHamiltonGraph<UndirectedAdjacencyMatrixGraph>(10, 70);

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