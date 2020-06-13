#pragma once

#include <iostream>
#include <vector>
#include <list>

#include <graphs/Graph/UndirectedGraph.hpp>

// I assume that columns describes each vertex (because its number is constant)
// and each row describes each edge (because its number can be modified)
// Adding or removing rows is easier than doing the same for edges

class UndirectedIncidenceMatrixGraph : public UndirectedGraph {
public:
    using IncidenceMatrix = std::list<std::vector<int>>;

    UndirectedIncidenceMatrixGraph(std::size_t verticesNumber);

    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;
    virtual bool containsEdge(int startVertex, int endVertex) const override;

    virtual std::list<int> getSuccessors(int vertex) const override;
    virtual std::list<int> getPredecessors(int vertex) const override;

    virtual std::size_t getIndegree(int vertex) const override;
    virtual std::size_t getOutdegree(int vertex) const override;

    virtual void dedicatedPrint(std::ostream& stream) const override;
    
private:
    IncidenceMatrix::const_iterator findEdgeRow(int startVertex, int endVertex) const;

protected:
    IncidenceMatrix matrix;
};