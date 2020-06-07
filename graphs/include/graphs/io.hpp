#pragma once

#include <iostream>
#include <array>
#include <queue>
#include <vector>
#include <list>
#include <graphs/Matrix/Matrix.hpp>

#define DBG(x) std::cerr << #x << " = " << x << '\n';
#define dbg std::cerr << "[DBG] " 

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::list<T>& container) {
    for (const auto& el : container) {
        stream << el << ' ';
    }
    
    return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& container) {
    for (const auto& el : container) {
        stream << el << ' ';
    }
    
    return stream;
}

template <typename T, std::size_t N>
std::ostream& operator<<(std::ostream& stream, const std::array<T, N>& container) {
    for (const auto& el : container) {
        stream << el << ' ';
    }
    
    return stream;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, std::queue<T> queue) {
    while (!queue.empty()) {
        stream << queue.front() << ' ';
        queue.pop();
    }

    return stream;
}
