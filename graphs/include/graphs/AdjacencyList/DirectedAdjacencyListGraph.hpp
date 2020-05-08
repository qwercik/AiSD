#pragma once

#include <algorithm>
#include <vector>
#include <list>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/io.hpp>

class DirectedAdjacencyListGraph : public Graph {
public:
    DirectedAdjacencyListGraph(std::size_t verticesNumber);

    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;
    
    virtual bool containsEdge(int startVertex, int endVertex) const override;
    virtual std::list<int> getAdjacentVertices(int vertex) const override;

protected:
    std::vector<std::list<int>> lists;
};