#pragma once

#include <iostream>
#include <cstddef>
#include <list>

class Graph {
public:
    Graph(std::size_t verticesNumber);

    std::size_t getVerticesNumber() const;

    virtual void addEdge(int startVertex, int endVertex) = 0;
    virtual void removeEdge(int startVertex, int endVertex) = 0;

    virtual bool containsEdge(int startVertex, int endVertex) const = 0;
    virtual std::list<int> getSuccessors(int vertex) const = 0;
    virtual std::list<int> getPredecessors(int vertex) const = 0;

    void print(std::ostream& stream) const;

protected:
    std::size_t verticesNumber;
};

std::ostream& operator<<(std::ostream& stream, const Graph& graph);
