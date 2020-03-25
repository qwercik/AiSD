#pragma once

#include <vector>
#include <utility>
#include <cstdlib>
#include "../io.hpp"
#include <iostream>

using PivotChooseFunction = int(*)(int, int);

inline int randomInt(int start, int end) {
	return rand() % (end - start + 1) + start;
}

template <typename T>
int partition(std::vector<T>& data, int beginIndex, int lastIndex, int pivotIndex) {
	int limitIndex = beginIndex;
	std::swap(data[pivotIndex], data[lastIndex]);
	pivotIndex = lastIndex;

	for (int index = beginIndex; index < lastIndex; ++index) {
		if (data[index] < data[pivotIndex]) {
			std::swap(data[limitIndex], data[index]);
			limitIndex++;
		}
	}

	std::swap(data[limitIndex], data[pivotIndex]);
	return limitIndex;
}

template <typename T>
void quickSort(std::vector<T>& data, int beginIndex, int lastIndex, PivotChooseFunction choosePivot) {
	//std::cerr << "quickSort(data, " << beginIndex << ", " << lastIndex << ")\n";
	if (beginIndex >= lastIndex) {
		return;
	}
	
	int pivotIndex = choosePivot(beginIndex, lastIndex);
	//std::cerr << "\tpivot = " << data[pivotIndex] << "(index " << pivotIndex << ")\n\t";
	//print(std::vector<int>(data.begin() + beginIndex, data.begin() + lastIndex + 1));
	pivotIndex = partition(data, beginIndex, lastIndex, pivotIndex);
	//std::cerr << "\tpivot = " << data[pivotIndex] << "(index " << pivotIndex << ")\n\t";
	//print(std::vector<int>(data.begin() + beginIndex, data.begin() + lastIndex + 1));

	quickSort(data, beginIndex, pivotIndex - 1, choosePivot);
	quickSort(data, pivotIndex + 1, lastIndex, choosePivot);
}

template <typename T>
void quickSortRight(std::vector<T>& data) {
	quickSort(data, 0, data.size() - 1, [](int beginIndex, int lastIndex) {
		return lastIndex;
	});
}

template <typename T>
void quickSortRandom(std::vector<T>& data) {
	quickSort(data, 0, data.size() - 1, [](int beginIndex, int lastIndex) {
		return randomInt(beginIndex, lastIndex);
	});
}

