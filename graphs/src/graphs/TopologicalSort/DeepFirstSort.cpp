#include <list>
#include <vector>

#include <graphs/DirectedGraph.hpp>
#include <graphs/TopologicalSort/DeepFirstSort.hpp>
#include <graphs/io.hpp>

std::list<int> DeepFirstSort::sort(DirectedGraph& graph) const {
    std::list<int> sortingResult;
    std::vector<bool> visitedVertices(graph.getVerticesNumber(), false);

    for (int index = 0; index < graph.getVerticesNumber(); ++index) {
        processVertex(graph, index, visitedVertices, sortingResult);
    }

    return sortingResult;
}

void DeepFirstSort::processVertex(const DirectedGraph& graph, int vertex, std::vector<bool>& visitedVertices, std::list<int>& sortResult) const {
    if (!visitedVertices[vertex]) {
        visitedVertices[vertex] = true;

        auto successors = graph.getSuccessors(vertex);
        for (const auto& successor : successors) {
            processVertex(graph, successor, visitedVertices, sortResult);
        }

        sortResult.push_front(vertex);
    }
}