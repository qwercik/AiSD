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
    virtual std::list<Item<Weight, Value>> solve(Weight capacity, const std::vector<Item<Weight, Value>>& items) const override {
        Matrix<Value> matrix(items.size(), capacity + 1);

        // Nie trzeba zerować macierzy, bo jest ona już wyzerowana ;)
        // Ustawiamy tylko pierwszy wiersz w taki sposób, aby nie powodowało to problemów później
        auto firstItemWeight = items[0].first;
        auto firstItemValue = items[0].second;
        for (std::size_t column = firstItemWeight; column < matrix.getWidth(); column++) {
            matrix.set(0, column, firstItemValue);
        }

        for (std::size_t row = 1; row < matrix.getHeight(); row++) {
            for (std::size_t column = 1; column < matrix.getWidth(); column++) {
                auto currentWeight = items[row].first;
                auto currentValue = items[row].second;

                if (column >= currentWeight) {
                    matrix.set(row, column, std::max(
                        matrix.get(row - 1, column),
                        currentValue + matrix.get(row - 1, column - currentWeight)
                    ));
                } else {
                    matrix.set(row, column, matrix.get(row - 1, column));
                }
            }
        }

        std::cout << '\n';
        for (std::size_t r = 0; r < matrix.getHeight(); r++) {
            for (std::size_t c = 0; c < matrix.getWidth(); c++) {
                std::cerr << matrix.get(r, c) << "\t";
            }

            std::cout << '\n';
        }
        std::cout << '\n';


        std::list<Item<Weight, Value>> resultList;
        std::size_t positionX = matrix.getWidth() - 1;
        std::size_t positionY = matrix.getHeight() - 1;

        for (; positionY > 0; positionY--) {
            auto currentValue = matrix.get(positionY, positionX);
            auto upValue = matrix.get(positionY - 1, positionX);
            if (currentValue != upValue || currentValue - items[positionY].second == matrix.get(positionY - 1, positionX - items[positionY].first)) {
                resultList.push_front(items[positionY]);
                positionX -= items[positionY].first;
            }
        }

        if (matrix.get(positionY, positionX) != 0) {
            resultList.push_front(items[positionY]);
        }

        return resultList;
    }
};