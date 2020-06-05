#pragma once

#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/UndirectedGraph.hpp>
#include <graphs/io.hpp>

class EulerCycleFind : public CycleFind {
private:
    const int START_VERTEX = 0;

public:
    EulerCycleFind(UndirectedGraph& graph) :
        graph(graph),
        currentVertex(START_VERTEX)
    {
        path.push_back(currentVertex);
        successors.push_back(graph.getSuccessors(currentVertex));
        countTotalEdges();
    }

    virtual std::list<int> find() override {
        findNextCycle();
        return path;
    }

    bool exist() {
        for (int i = 0; i < graph.getVerticesNumber(); ++i) {
            if (graph.getSuccessors(i).size() % 2 != 0) {
                return false;
            }
        }

        return true;
    }

private:
    // Returns true if Euler cycle has been already found
    // Otherwise returns false
    void findNextCycle() {
        while (!path.empty() && !successors.empty()) {
            while (successors.back().empty()) {
                int successor = path.back();
                path.pop_back();
                successors.pop_back();

                if (path.empty()) {
                    return;
                }
            
                int predecessor = path.back();
                graph.addEdge(predecessor, successor);
            }

            currentVertex = successors.back().front();
            successors.back().pop_front();

            if (path.size() == totalEdges) {
                return;
            }

            graph.removeEdge(path.back(), currentVertex);
            path.push_back(currentVertex);
            successors.push_back(graph.getSuccessors(currentVertex));
        }
    }

    void countTotalEdges() {
        totalEdges = 0;
        for (int i = 0; i < graph.getVerticesNumber(); ++i) {
            totalEdges += graph.getSuccessors(i).size();
        }
        totalEdges /= 2;
    }


    UndirectedGraph& graph;
    std::list<int> path;
    std::list<std::list<int>> successors;
    int currentVertex;

    int totalEdges;
};