#pragma once

#include <algorithm>
#include <vector>
#include <list>

#include <graphs/Graph.hpp>
#include <graphs/Matrix/Matrix.hpp>
#include <graphs/io.hpp>

class UndirectedAdjacencyListGraph : public Graph {
public:
    UndirectedAdjacencyListGraph(std::size_t verticesNumber);

    virtual void addEdge(int startVertex, int endVertex) override;
    virtual void removeEdge(int startVertex, int endVertex) override;
    virtual bool containsEdge(int startVertex, int endVertex) const override;

    virtual void print(std::ostream& stream) const override;

protected:
    std::vector<std::list<int>> lists;
};