#pragma once

#include <list>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/Matrix.hpp>

class UndirectedAdjacencyMatrixGraph : public Graph {
public:
    UndirectedAdjacencyMatrixGraph(std::size_t verticesNumber);
    
    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;

    virtual bool containsEdge(int startVertex, int endVertex) const override;
    virtual std::list<int> getAdjacentVertices(int vertex) const override;

protected:
    Matrix<int> matrix;
};