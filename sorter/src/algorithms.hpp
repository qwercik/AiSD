#pragma once

#include "algorithms/insertion.hpp"
#include "algorithms/bubble.hpp"
#include "algorithms/selection.hpp"
#include "algorithms/merge.hpp"
#include "algorithms/heap.hpp"
#include "algorithms/quick.hpp"
#include "algorithms/shell.hpp"
#include "algorithms/counting.hpp"

using SortingAlgorithm = void(*)(std::vector<int>&);
const std::unordered_map<std::string, SortingAlgorithm> supportedAlgorithms({
	{ "bubble", bubbleSort },
	{ "insertion", insertionSort },
	{ "selection", selectionSort },
	{ "merge", mergeSort },
	{ "quick-right", quickSortRight },
	{ "quick-rand", quickSortRandom },
	{ "heap", heapSort },
	{ "shell", shellSort },
	{ "counting", countingSortWithPresearch }
});

std::string supportedAlgorithmsList() {
	std::string list;
	for (const auto& algorithm : supportedAlgorithms) {
		list += algorithm.first + ' ';
	}

	return list;
}
