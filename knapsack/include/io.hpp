#pragma once

#include <iostream>
#include <list>

#define dbg std::cerr << "[DBG] "
#define DBG(x) dbg << #x << " = " << x << '\n';

template <typename T>
std::ostream& operator<<(std::ostream& stream, const std::list<T>& list) {
    auto currentElement = list.begin();
    stream << *(currentElement++);

    while (currentElement != list.end()) {
        stream << ' ' << *(currentElement++);
    }

    return stream;
}