#pragma once

#include <vector>
#include <utility>

template <typename T>
int indexOfMinValue(const std::vector<T>& list) {
	int minIndex = 0;
	for (int index = 1; index < list.size(); ++index) {
		if (list[index] < list[minIndex]) {
			minIndex = index;
		}
	}

	return minIndex;
}

template <typename T>
void selectionSort(std::vector<T>& data) {
	for (int index = 0; index < data.size() - 1; ++index) {
		std::swap(data[index], data[index + indexOfMinValue(std::vector<int>(data.begin() + index, data.end()))]);
	}
}


