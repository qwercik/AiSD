#pragma once

#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/UndirectedGraph.hpp>

class HamiltonCycleFind : public CycleFind {
public:
    virtual std::list<int> find(UndirectedGraph& graph) const override {
        std::cerr << '\n';
        std::list<int> path;
        std::vector<bool> visited(graph.getVerticesNumber(), false);
        backend(graph, path, visited, 0);

        return path;
    }

private:
    // Returns true if Hamilton cycle has been already found
    // Otherwise returns false
    bool backend(UndirectedGraph& graph, std::list<int>& path, std::vector<bool>& visited, int vertex) const {
        visited[vertex] = true;
        path.push_back(vertex);

        for (auto successor : graph.getSuccessors(vertex)) {
            if (!visited[successor]) {
                if (backend(graph, path, visited, successor)) {
                    return true;
                }
            }
        }

        if (path.size() == graph.getVerticesNumber()) {
            if (graph.containsEdge(vertex, 0)) {
                return true;
            } else {
                visited[path.back()] = false;
                path.pop_back();
            }
        }

        return false;
    }
};