#pragma once

#include <vector>
#include <utility>

void insertionSort(std::vector<int>& data) {
	for (int unsortedValueIndex = 1; unsortedValueIndex < data.size(); ++unsortedValueIndex) {
		while (unsortedValueIndex >= 1 && data[unsortedValueIndex - 1] > data[unsortedValueIndex]) {
			std::swap(data[unsortedValueIndex - 1], data[unsortedValueIndex]);
			--unsortedValueIndex;
		}
	}
}

