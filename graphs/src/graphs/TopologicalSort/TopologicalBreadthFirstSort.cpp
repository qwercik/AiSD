#include <list>
#include <queue>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/TopologicalSort/TopologicalBreadthFirstSort.hpp>
#include <graphs/io.hpp>

std::list<int> TopologicalBreadthFirstSort::sort(DirectedGraph& graph) const {
    std::list<int> sortingResult;
    std::queue<int> verticesWithoutPredecessors;

    for (std::size_t index = 0; index < graph.getVerticesNumber(); ++index) {
        if (graph.getIndegree(index) == 0) {
            verticesWithoutPredecessors.push(index);
        }
    }

    while (!verticesWithoutPredecessors.empty()) {
        auto currentVertex = verticesWithoutPredecessors.front();
        verticesWithoutPredecessors.pop();
        sortingResult.push_back(currentVertex);

        for (const auto& successor : graph.getSuccessors(currentVertex)) {
            graph.removeEdge(currentVertex, successor);
            
            if (graph.getIndegree(successor) == 0) {
                verticesWithoutPredecessors.push(successor);
            }
        }
    }

    // Here graph should not have any edges

    return sortingResult;
}