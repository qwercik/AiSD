#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>

#include "algorithms.hpp"
#include "io.hpp"

int main(int argc, char *argv[]) {
	if (argc < 2 || argc > 3) {
		std::cerr << "Incorrect usage\n";
		std::cerr << "Use: " << argv[0] << " <algorithm> [benchmark]\n";
		std::cerr << "Where <algorithm> is one from the following:\n";
		std::cerr << supportedAlgorithmsList() << '\n';
		std::cerr << "Type benchmark as parameter if you would like not to print output, but only measure a run time of algorithm\n";
		return EXIT_FAILURE;
	}

	bool benchmarkMode = false;
	if (argc == 3 && std::string(argv[2]) == "benchmark") {
		benchmarkMode = true;
	}

	std::string choosenAlgorithm = argv[1];
	auto iterator = supportedAlgorithms.find(choosenAlgorithm);
	if (iterator == supportedAlgorithms.end()) {
		std::cerr << "Choosen algorithm is not supported\n";
		std::cerr << "Choose one from the following:\n";
		std::cerr << supportedAlgorithmsList() << '\n';
		return EXIT_FAILURE;
	}

	SortingAlgorithm sortingAlgorithm = iterator->second;

	std::vector<int> data;
	loadFromStream(data);
	sortingAlgorithm(data);
	
	if (!benchmarkMode) {
		print(data);
	}
}
