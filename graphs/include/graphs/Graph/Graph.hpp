#pragma once

#include <iostream>
#include <stdexcept>
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

    virtual std::size_t getIndegree(int vertex) const = 0;
    virtual std::size_t getOutdegree(int vertex) const = 0;

    virtual std::size_t maxEdges() const = 0;
    virtual std::size_t totalEdges() const = 0;
    bool isComplete() const;

    void print(std::ostream& stream) const;
    virtual void dedicatedPrint(std::ostream& stream) const = 0;

    bool correctVertex(std::size_t vertex) const;

protected:
    void handleIfVertexNotInRange(std::size_t vertex) const;
    void handleIfEdgeNotExist(std::size_t predecessor, std::size_t successor) const;

    std::size_t verticesNumber;
};

std::ostream& operator<<(std::ostream& stream, const Graph& graph);
