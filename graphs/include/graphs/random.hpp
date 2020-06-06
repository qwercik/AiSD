#pragma once

#include <array>
#include <cstdlib>
#include <algorithm>

/**
 * It's wrapper for generating random integer
 * <start> is included and <end> is excluded from generated range
 * For example (3, 7) means range {3, 4, 5, 6}
 */
int randomInteger(int start, int end) {
    return start + rand() % (end - start);
}

template <int N>
std::array<int, N> randomIntegers(int start, int end) {
    std::array<int, N> array;
    for (int currentIndex = 0; currentIndex < N; ++currentIndex) {
        do {
            array[currentIndex] = randomInteger(start, end);
        } while (std::find(array.begin(), array.begin() + currentIndex, array[currentIndex]) != array.begin() + currentIndex);
    }

    return array;
}
