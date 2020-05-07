#include <iostream>
#include <memory>
#include <graphs/Graph.hpp>

int main() {
	std::unique_ptr<Graph> graph;
	std::cout << *graph;
}
