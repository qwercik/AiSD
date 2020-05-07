#pragma once

#include <graphs/Graph.hpp>
#include <graphs/GrowableMatrix.hpp>

// I assume that columns describes each vertex (because its number is constant)
// and each row describes each edge (because its number can be modified)
// Adding or removing rows is easier than doing the same for edges

class DirectedIncidenceMatrixGraph : public Graph {
public:
    DirectedIncidenceMatrixGraph(std::size_t verticesNumber) :
        Graph(verticesNumber),
        matrix(0, verticesNumber)
    {}

    virtual void addEdge(int startVertex, int endVertex) override {
        matrix.addRow();
        auto edgeIndex = matrix.getRows() - 1;

        matrix.set(edgeIndex, startVertex, 1);
        matrix.set(edgeIndex, endVertex, -1);
    }

    virtual void removeEdge(int startVertex, int endVertex) override {
        auto edgeIndex = findEdgeRow(startVertex, endVertex);
        matrix.removeRow(edgeIndex);
    }

    virtual bool containsEdge(int startVertex, int endVertex) const override {
        return findEdgeRow(startVertex, endVertex) != -1;
    }

    virtual void print(std::ostream& stream) const override {
        stream << matrix;
    }

private:
    int findEdgeRow(int startVertex, int endVertex) const {
        for (int row = 0; row < matrix.getRows(); ++row) {
            if (matrix.get(row, startVertex) == 1 && matrix.get(row, endVertex) == -1) {
                return row;
            }
        }

        // If not find
        return -1;
    }

protected:
    GrowableMatrix<int> matrix;
};