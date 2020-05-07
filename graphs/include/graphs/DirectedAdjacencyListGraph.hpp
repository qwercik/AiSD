#pragma once

#include <graphs/Graph.hpp>
#include <graphs/Matrix.hpp>
#include <algorithm>
#include <vector>
#include <list>
#include <graphs/io.hpp>

class DirectedAdjacencyListGraph : public Graph {
public:
    DirectedAdjacencyListGraph(std::size_t verticesNumber) :
        Graph(verticesNumber),
        lists(verticesNumber, std::list<int>())
    {}

    virtual void addEdge(int startVertex, int endVertex) override {
        lists[startVertex].push_back(endVertex);
    }

    virtual void removeEdge(int startVertex, int endVertex) override {
        lists[startVertex].remove(endVertex);
    }

    virtual bool containsEdge(int startVertex, int endVertex) const override {
        auto current = lists[startVertex];
        return std::find(current.begin(), current.end(), endVertex) != current.end();
    }

    virtual void print(std::ostream& stream) const override {
        for (std::size_t i = 0; i < this->verticesNumber; ++i) {
            stream << "Vertex nr " << i << ": " << lists[i] << '\n';
        }
    }

protected:
    std::vector<std::list<int>> lists;
};