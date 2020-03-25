#pragma once

#include <vector>
#include <utility>

template <typename T>
void bubbleSort(std::vector<T>& data) {
	for (int i = 0; i < data.size() - 1; ++i) {
		for (int j = 0; j < data.size() - i - 1; ++j) {
			if (data[j] > data[j + 1]) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}

