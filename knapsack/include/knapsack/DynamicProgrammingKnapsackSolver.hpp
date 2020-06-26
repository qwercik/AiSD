#pragma once

#include <list>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <knapsack/KnapsackSolver.hpp>
#include <knapsack/Item.hpp>

class MatrixOutOfRangeException : public std::runtime_error {
public:
    MatrixOutOfRangeException(const std::string& message) :
        std::runtime_error(message)
    {}
};

template <typename T>
class Matrix {
public:
    Matrix(std::size_t height, std::size_t width) :
        data(width * height, 0),
        width(width),
        height(height)
    {
    }

    T get(std::size_t positionY, std::size_t positionX) const {
        throwExceptionIfOutOfRange(positionY, positionX);
        return data[index(positionY, positionX)];
    }

    void set(std::size_t positionY, std::size_t positionX, T value) {
        throwExceptionIfOutOfRange(positionY, positionX);
        data[index(positionY, positionX)] = value;
    }

    std::size_t getHeight() const {
        return this->height;
    }

    std::size_t getWidth() const {
        return this->width;
    }

private:
    std::size_t inline index(std::size_t positionY, std::size_t positionX) const {
        return positionY * this->width + positionX;
    }

    void throwExceptionIfOutOfRange(std::size_t positionY, std::size_t positionX) const {
        if (positionY >= height && positionX >= width) {
            throw MatrixOutOfRangeException("Matrix out of range at (y=" + std::to_string(positionY) + ", x=" + std::to_string(positionX) + ")");
        }
    }

    std::vector<T> data;
    std::size_t height;
    std::size_t width;
};

template <typename Weight, typename Value>
class DynamicProgrammingKnapsackSolver : public KnapsackSolver<Weight, Value> {
public:
    virtual std::list<Item<Weight, Value>> solve(Weight capacity, const std::vector<Item<Weight, Value>>& allItems) const override {
        Matrix<Value> matrix = createValuesMatrix(capacity, allItems);
        return getItemsListFromMatrix(matrix, allItems);
    }

    Matrix<Value> createValuesMatrix(Weight capacity, const std::vector<Item<Weight, Value>>& allItems) const {
        Matrix<Value> matrix(allItems.size(), capacity + 1);
        
        // Nie trzeba zerować macierzy, bo jest ona już wyzerowana ;)
        // Ustawiamy tylko pierwszy wiersz w taki sposób, aby nie powodowało to problemów później
        auto firstItemWeight = allItems[0].first;
        auto firstItemValue = allItems[0].second;
        for (std::size_t column = firstItemWeight; column < matrix.getWidth(); column++) {
            matrix.set(0, column, firstItemValue);
        }

        for (std::size_t row = 1; row < matrix.getHeight(); row++) {
            for (std::size_t column = 1; column < matrix.getWidth(); column++) {
                matrix.set(row, column, calculateMatrixCellValue(matrix, allItems, row, column));
            }
        }

        return matrix;
    }

    Value calculateMatrixCellValue(const Matrix<Value>& matrix, const std::vector<Item<Weight, Value>>& allItems, std::size_t row, std::size_t column) const {
        auto currentWeight = allItems[row].first;
        auto currentValue = allItems[row].second;

        if (column >= currentWeight) {
            return std::max(
                matrix.get(row - 1, column),
                currentValue + matrix.get(row - 1, column - currentWeight)
            );
        } else {
            return matrix.get(row - 1, column);
        }
    }

    std::list<Item<Weight, Value>> getItemsListFromMatrix(const Matrix<Value>& matrix, const std::vector<Item<Weight, Value>>& allItems) const {
        std::list<Item<Weight, Value>> resultList;
        std::size_t positionX = matrix.getWidth() - 1;
        std::size_t positionY = matrix.getHeight() - 1;

        for (; positionY > 0; positionY--) {
            auto currentValue = matrix.get(positionY, positionX);
            auto upValue = matrix.get(positionY - 1, positionX);
            if (currentValue != upValue) {
                resultList.push_front(allItems[positionY]);
                positionX -= allItems[positionY].first;
            }
        }

        if (matrix.get(positionY, positionX) != 0) {
            resultList.push_front(allItems[positionY]);
        }

        return resultList;
    }
};