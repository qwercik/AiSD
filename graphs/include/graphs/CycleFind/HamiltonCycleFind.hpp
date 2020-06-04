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
    virtual std::list<int> find(UndirectedGraph& graph) const override {
        std::list<int> path;
        std::vector<bool> visited(graph.getVerticesNumber(), false);
        backend(graph, path, visited, START_VERTEX);
        return path;
    }

private:
    // Returns true if Hamilton cycle has been already found
    // Otherwise returns false
    void backend(UndirectedGraph& graph, std::list<int>& path, std::vector<bool>& visited, int vertex) const {
        path.push_back(vertex);
        visited[vertex] = true;

        if (path.size() < graph.getVerticesNumber()) {    
            for (auto successor : graph.getSuccessors(vertex)) {
                if (!visited[successor]) {
                    backend(graph, path, visited, successor);
                }
            }
        } else if (graph.containsEdge(vertex, START_VERTEX)) {
            std::cerr << "[DBG] " << path << '\n';
        }

        visited[vertex] = false;
        path.pop_back();
    }
};