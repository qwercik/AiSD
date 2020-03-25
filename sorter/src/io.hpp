#pragma once

#include <iostream>
#include <vector>

template <typename T>
void loadFromStream(std::vector<T>& data) {
	T value;
	while (std::cin >> value) {
		data.push_back(value);
	}
}

template <typename T>
void print(const std::vector<T>& data) {
	for (auto element : data) {
		std::cout << element << ' ';
	}

	std::cout << '\n';
}
