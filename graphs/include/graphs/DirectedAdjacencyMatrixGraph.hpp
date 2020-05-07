#pragma once

#include <graphs/Graph.hpp>
#include <graphs/Matrix.hpp>

class DirectedAdjacencyMatrixGraph : public Graph {
public:
    DirectedAdjacencyMatrixGraph(std::size_t verticesNumber) :
        Graph(verticesNumber),
        matrix(verticesNumber, verticesNumber)
    {}

    virtual void addEdge(int startVertex, int endVertex) override {
        matrix.increment(startVertex, endVertex);
    }

    virtual void removeEdge(int startVertex, int endVertex) override {
        matrix.decrement(startVertex, endVertex);
    }

    virtual bool containsEdge(int startVertice, int endVertice) const override {
        return matrix.get(startVertice, endVertice) > 0;
    }

    virtual void print(std::ostream& stream) const override {
        stream << matrix;
    }

protected:
    Matrix<int> matrix;
};