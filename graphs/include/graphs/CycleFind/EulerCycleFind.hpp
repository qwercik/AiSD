#pragma once

#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/UndirectedGraph.hpp>
#include <graphs/io.hpp>

/** Remember that graph structure is destroyed after using this class!
 **/
class EulerCycleFind : public CycleFind {
public:
    EulerCycleFind(UndirectedGraph& graph) :
        graph(graph),
        anyCycleExist(true)
    {
        startingVertex = 0;
        for (; startingVertex < graph.getVerticesNumber(); ++startingVertex) {
            if (graph.getSuccessors(startingVertex).size() != 0) {
                break;
            }
        }

        if (startingVertex == graph.getVerticesNumber()) {
            anyCycleExist = false;
            return;
        }

        if (!checkExist()) {
            anyCycleExist = false;
            return;
        }

        currentVertex = startingVertex;
        path.push_back(startingVertex);
        successors.push_back(graph.getSuccessors(startingVertex));
        totalEdges = graph.totalEdges();
    }

    virtual std::list<int> find() override {
        if (!anyCycleExist) {
            return {};
        } else {
            findNextCycle();
            return path;
        }
    }

private:
    bool checkExist() {
        for (int i = 0; i < graph.getVerticesNumber(); ++i) {
            if (graph.getSuccessors(i).size() % 2 != 0) {
                return false;
            }
        }

        return true;
    }

    // Returns true if Euler cycle has been already found
    // Otherwise returns false
    void findNextCycle() {
        while (!path.empty() && !successors.empty()) {
            while (successors.back().empty()) {
                int successor = path.back();
                path.pop_back();
                successors.pop_back();

                if (path.empty() || successors.empty()) {
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

    int startingVertex;
    int totalEdges;
    bool anyCycleExist;

    UndirectedGraph& graph;
    std::list<int> path;
    std::list<std::list<int>> successors;
    int currentVertex;
};