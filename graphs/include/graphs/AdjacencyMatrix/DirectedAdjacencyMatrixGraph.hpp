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
    virtual std::list<int> getSuccessors(int vertex) const override;
    virtual std::list<int> getPredecessors(int vertex) const override;
    
    virtual void dedicatedPrint(std::ostream& stream) const override;
    
protected:
    Matrix<int> matrix;
};