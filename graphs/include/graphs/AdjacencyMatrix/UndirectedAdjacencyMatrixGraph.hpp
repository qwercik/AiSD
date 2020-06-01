#pragma once

#include <list>

#include <graphs/UndirectedGraph.hpp>
#include <graphs/Matrix/Matrix.hpp>

class UndirectedAdjacencyMatrixGraph : public UndirectedGraph {
public:
    UndirectedAdjacencyMatrixGraph(std::size_t verticesNumber);
    
    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;

    virtual bool containsEdge(int startVertex, int endVertex) const override;
    virtual std::list<int> getSuccessors(int vertex) const override;
    virtual std::list<int> getPredecessors(int vertex) const override;

protected:
    Matrix<int> matrix;
};