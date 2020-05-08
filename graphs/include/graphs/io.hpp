#pragma once

#include <iostream>
#include <vector>
#include <list>

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
