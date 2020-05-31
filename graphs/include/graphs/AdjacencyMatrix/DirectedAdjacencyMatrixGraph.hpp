#pragma once

#include <list>

#include <graphs/DirectedGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>

class DirectedAdjacencyMatrixGraph : public DirectedGraph {
public:
    DirectedAdjacencyMatrixGraph(std::size_t verticesNumber);

    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;

    virtual bool containsEdge(int startVertex, int endVertex) const override;
    virtual std::list<int> getAdjacentVertices(int vertex) const override;
    
protected:
    Matrix<int> matrix;
};