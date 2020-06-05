#pragma once

#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/UndirectedGraph.hpp>
#include <graphs/io.hpp>

class HamiltonCycleFind : public CycleFind {
private:
    const int START_VERTEX = 0;

public:
    HamiltonCycleFind(UndirectedGraph& graph) :
        graph(graph),
        visited(graph.getVerticesNumber(), false),
        currentVertex(START_VERTEX)
    {
        path.push_back(currentVertex);
        successors.push_back(graph.getSuccessors(currentVertex));
        visited[currentVertex] = true;
    }

    virtual std::list<int> find() override {
        findNextCycle();
        return path;
    }

private:
    // Returns true if Hamilton cycle has been already found
    // Otherwise returns false
    bool findNextCycle() {
        while (!path.empty() && !successors.empty()) {
            while (successors.back().empty()) {
                visited[path.back()] = false;
                path.pop_back();
                successors.pop_back();

                if (path.empty() || successors.empty()) {
                    return false;
                }
            }

            currentVertex = successors.back().front();
            successors.back().pop_front();

            if (path.size() == graph.getVerticesNumber() && currentVertex == START_VERTEX) {
                return true;
            }
            
            if (!visited[currentVertex]) {
                visited[currentVertex] = true;
                path.push_back(currentVertex);
                successors.push_back(graph.getSuccessors(currentVertex));
            }
        }

        return false;
    }

    UndirectedGraph& graph;
    std::vector<bool> visited;
    std::list<int> path;
    std::list<std::list<int>> successors;
    int currentVertex;
};