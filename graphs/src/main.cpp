#include <iostream>
#include <memory>
#include <graphs/graphs.hpp>

void test() {
	UndirectedGraphGenerator gen;
	auto graph = gen.generateNeitherEulerNorHamiltonGraph<UndirectedAdjacencyMatrixGraph>(10, 30);

	HamiltonCycleFind hamiltonFinder(graph);
	EulerCycleFind eulerFinder(graph);

	std::cout << graph << std::flush;
	std::cout << "Hamilton cycle: " << hamiltonFinder.find() << std::endl;
	std::cout << "Euler cycle: " << eulerFinder.find() << std::endl;
}

int main() {
	srand(time(nullptr));
	test();
}