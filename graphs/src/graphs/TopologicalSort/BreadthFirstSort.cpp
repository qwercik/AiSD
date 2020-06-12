#include <list>
#include <queue>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSort/BreadthFirstSort.hpp>
#include <graphs/io.hpp>

bool BreadthFirstSort::sort(DirectedGraph& graph, std::list<int>& sortingResult) const {
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

    return true;
}