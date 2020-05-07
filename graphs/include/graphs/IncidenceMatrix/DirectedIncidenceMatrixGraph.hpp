#pragma once

#include <iostream>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/GrowableMatrix.hpp>

// I assume that columns describes each vertex (because its number is constant)
// and each row describes each edge (because its number can be modified)
// Adding or removing rows is easier than doing the same for edges

class DirectedIncidenceMatrixGraph : public Graph {
public:
    DirectedIncidenceMatrixGraph(std::size_t verticesNumber);

    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;
    virtual bool containsEdge(int startVertex, int endVertex) const override;
    
    virtual void print(std::ostream& stream) const override;

private:
    int findEdgeRow(int startVertex, int endVertex) const;

protected:
    GrowableMatrix<int> matrix;
};