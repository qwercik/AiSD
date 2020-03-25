#pragma once

#include <vector>
#include <utility>

template <typename T>
void fixHeap(std::vector<T>& data, int parentIndex, int heapSize) {
	int leftChildIndex = 2 * parentIndex + 1;
	int rightChildIndex = 2 * parentIndex + 2;

	int maxIndex = parentIndex;
	if (leftChildIndex < heapSize && data[leftChildIndex] > data[maxIndex]) {
		maxIndex = leftChildIndex;
	}
	
	if (rightChildIndex < heapSize && data[rightChildIndex] > data[maxIndex]) {
		maxIndex = rightChildIndex;
	}

	// Jeżeli dany element nie jest rodzicem innego elementu, to poniższy if na pewno się nie wykona
	if (maxIndex != parentIndex) {
		std::swap(data[maxIndex], data[parentIndex]);
		fixHeap(data, maxIndex, heapSize);
	}
}

template <typename T>
void heapSort(std::vector<T>& data) {
	// Przejeżdżamy po wszystkich istniejących rodzicach - ten ostatni ma indeks data.size() / 2
	for (int parentIndex = data.size() / 2; parentIndex >= 0; --parentIndex) {
		fixHeap(data, parentIndex, data.size());
	}

	for (int heapSize = data.size() - 1; heapSize > 0; --heapSize) {
		std::swap(data[0], data[heapSize]);
		fixHeap(data, 0, heapSize);
	}
}

