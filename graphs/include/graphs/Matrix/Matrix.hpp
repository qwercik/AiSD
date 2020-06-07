#pragma once

#include <cstddef>
#include <vector>
#include <iostream>

template <typename T>
class Matrix {
public:
    Matrix(std::size_t rows, std::size_t columns) :
        rows(rows),
        columns(columns),
        values(rows * columns, 0)
    {}

    void set(std::size_t row, std::size_t column, T value) {
        auto index = getIndex(row, column);
        values[index] = value;
    }

    void increment(std::size_t row, std::size_t column) {
        auto index = getIndex(row, column);
        values[index]++;
    }

    void decrement(std::size_t row, std::size_t column) {
        auto index = getIndex(row, column);
        values[index]--;
    }

    T get(std::size_t row, std::size_t column) const {
        auto index = getIndex(row, column);
        return values[index];
    }

    std::size_t getRows() const {
        return rows;
    }

    std::size_t getColumns() const {
        return columns;
    }

protected:
    inline std::size_t getIndex(std::size_t row, std::size_t column) const {
        return row * columns + column;
    }

    std::size_t rows;
    std::size_t columns;
    std::vector<T> values;
};

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Matrix<T>& matrix) {
    for (std::size_t row = 0; row < matrix.getRows(); ++row) {
        for (std::size_t column = 0; column < matrix.getColumns(); ++column) {
            stream << matrix.get(row, column) << ' ';
        }

        stream << '\n';
    }

    return stream;
}
