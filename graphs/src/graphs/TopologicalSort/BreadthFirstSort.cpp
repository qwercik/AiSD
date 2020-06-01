#include <list>
#include <queue>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSort/BreadthFirstSort.hpp>
#include <graphs/io.hpp>

std::list<int> BreadthFirstSort::sort(DirectedGraph& graph) const {
    std::list<int> sortingResult;
    std::queue<int> verticesWithoutPredecessors;

    for (std::size_t index = 0; index < graph.getVerticesNumber(); ++index) {
        auto predecessors = graph.getPredecessors(index);
        if (predecessors.size() == 0) {
            verticesWithoutPredecessors.push(index);
        }
    }

    while (!verticesWithoutPredecessors.empty()) {
        auto currentVertex = verticesWithoutPredecessors.front();
        verticesWithoutPredecessors.pop();
        sortingResult.push_back(currentVertex);

        for (const auto& successor : graph.getSuccessors(currentVertex)) {
            graph.removeEdge(currentVertex, successor);
            
            auto successorPrecessors = graph.getPredecessors(successor);
            if (successorPrecessors.size() == 0) {
                verticesWithoutPredecessors.push(successor);
            }
        }
    }

    // Here graph should not have any edges

    return sortingResult;
}