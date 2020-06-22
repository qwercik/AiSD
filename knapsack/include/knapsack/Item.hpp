#pragma once

#include <utility>

template <typename Weight, typename Value>
using Item = std::pair<Weight, Value>;

template <typename Weight, typename Iterator>
Weight totalItemsWeight(Iterator begin, Iterator end) {
    Weight total = 0;
    for(; begin != end; ++begin) {
        total += (*begin).first;
    }

    return total;
}

template <typename Value, typename Iterator>
Value totalItemsValue(Iterator begin, Iterator end) {
    Value total = 0;
    for(; begin != end; ++begin) {
        total += (*begin).first;
    }

    return total;
}