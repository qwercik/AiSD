#pragma once

#include <vector>
#include <utility>

template <typename T>
void shellSort(std::vector<T>& data) {
	for (int distance = data.size() / 2; distance >= 1; distance /= 2) {
		for (int currentIndex = distance; currentIndex < data.size(); ++currentIndex) {
			while (currentIndex >= distance && data[currentIndex - distance] > data[currentIndex]) {
				std::swap(data[currentIndex - distance], data[currentIndex]);
				currentIndex -= distance;
			}
		}
	}
}

