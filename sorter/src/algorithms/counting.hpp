#pragma once

#include <vector>
#include <array>
#include <utility>

template <typename It>
void printIt(It begin, It end) {
	for (; begin < end; ++begin) {
		std::cout << *begin << ' ';
	}
	std::cout << '\n';
}


void countingSort(std::vector<int>& data, int maxValue) {
	std::vector<int> valuesCopy(data);
	
	std::vector<int> histogram(maxValue + 1);
	for (auto& el : histogram) {
		el = 0;
	}

	for (auto el : data) {
		++histogram[el];
	}

	for (int i = 1; i <= maxValue; ++i) {
		histogram[i] += histogram[i - 1];
	}

	for (int i = data.size() - 1; i >= 0; --i) {
		int value = valuesCopy[i];
		data[--histogram[value]] = value;
	}
}


// Zakładam, że w danych na pewno są liczby całkowite nieujemne
void countingSortWithPresearch(std::vector<int>& data) {
	int maxValue = data[0];
	for (auto el : data) {	
		if (el > maxValue) {
			maxValue = el;
		}
	}

	countingSort(data, maxValue);
}

// Zakładam, że największą liczbą w ciągu danych jest 100
void countingSortSmallNumbers(std::vector<int>& data) {
	countingSort(data, 100);
}
