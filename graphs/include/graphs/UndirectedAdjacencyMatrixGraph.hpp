#pragma once

#include <graphs/Graph.hpp>
#include <graphs/Matrix.hpp>

class UndirectedAdjacencyMatrixGraph : public Graph {
public:
    UndirectedAdjacencyMatrixGraph(std::size_t verticesNumber) :
        Graph(verticesNumber),
        matrix(verticesNumber, verticesNumber)
    {}

    virtual void addEdge(int startVertex, int endVertex) override {
        matrix.increment(startVertex, endVertex);
        matrix.increment(endVertex, startVertex);
    }

    virtual void removeEdge(int startVertex, int endVertex) override {
        matrix.decrement(startVertex, endVertex);
        matrix.decrement(endVertex, startVertex);
    }

    virtual bool containsEdge(int startVertex, int endVertex) const override {
        // We assumes integrity of adjacency matrix
        return matrix.get(startVertex, endVertex) > 0;
    }

    virtual void print(std::ostream& stream) const override {
        stream << matrix;
    }

protected:
    Matrix<int> matrix;
};