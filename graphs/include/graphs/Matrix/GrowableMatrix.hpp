#pragma once

#include <cstddef>
#include <vector>
#include <iostream>
#include <algorithm>

#include <graphs/Matrix/Matrix.hpp>


// Due to simplicity
// GrowableMatrix is only growable for rows
template <typename T>
class GrowableMatrix : public Matrix<T> {
public:
    GrowableMatrix(std::size_t rows, std::size_t columns) :
        Matrix<T>(rows, columns)
    {}

    void addRow() {
        this->values.resize(this->values.size() + this->columns, 0);
        this->rows++;
    }

    void removeRow(std::size_t row) {
        auto rowBegin = this->values.begin() + row * this->columns;
        auto rowEnd = rowBegin + this->columns;

        this->values.erase(rowBegin, rowEnd);
        this->rows--;
    }
};
