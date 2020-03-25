#pragma once

#include <vector>
#include <utility>

template <typename T>
void merge(std::vector<T> left, std::vector<T> right, std::vector<T>& result) {
	int leftIndex = 0;
   	int	rightIndex = 0;
   	int resultIndex = 0;

	while (leftIndex < left.size() && rightIndex < right.size()) {
		if (left[leftIndex] <= right[rightIndex]) {
			result[resultIndex] = left[leftIndex];
			leftIndex++;
		} else {
			result[resultIndex] = right[rightIndex];
			rightIndex++;
		}

		resultIndex++;
	}

	while (leftIndex < left.size()) {
		result[resultIndex] = left[leftIndex];
		leftIndex++;
		resultIndex++;
	}

	while (rightIndex < right.size()) {
		result[resultIndex] = right[rightIndex];
		rightIndex++;
		resultIndex++;
	}
}

template <typename T>
void mergeSort(std::vector<T>& data) {
	if (data.size() == 1) {
		return;
	}

	std::vector<T> left(data.begin(), data.begin() + data.size() / 2);
	std::vector<T> right(data.begin() + data.size() / 2, data.end());

	mergeSort(left);
	mergeSort(right);

	merge(left, right, data);
}

