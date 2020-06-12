#include <list>
#include <vector>

#include <graphs/Graph/DirectedGraph.hpp>
#include <graphs/TopologicalSort/TopologicalDeepFirstSort.hpp>
#include <graphs/TopologicalSort/TopologicalSortCycleFoundException.hpp>
#include <graphs/io.hpp>

std::list<int> TopologicalDeepFirstSort::sort(DirectedGraph& graph) const {
    std::list<int> sortingResult;
    std::vector<VertexColor> verticesColors(graph.getVerticesNumber(), VertexColor::NOT_VISITED);

    for (int index = 0; index < graph.getVerticesNumber(); ++index) {
        if (!processVertex(graph, index, verticesColors, sortingResult)) {
            throw TopologicalSortCycleFoundException("Graph shouldn\'t contain any cycles, but it does");
        }
    }

    return sortingResult;
}

bool TopologicalDeepFirstSort::processVertex(const DirectedGraph& graph, int vertex, std::vector<VertexColor>& verticesColors, std::list<int>& sortResult) const {
    if (verticesColors[vertex] == VertexColor::PROCESSING) {
        return false;
    }

    if (verticesColors[vertex] == VertexColor::NOT_VISITED) {
        verticesColors[vertex] = VertexColor::PROCESSING;

        auto successors = graph.getSuccessors(vertex);
        for (const auto& successor : successors) {
            if (!processVertex(graph, successor, verticesColors, sortResult)) {
                return false;
            }
        }

        verticesColors[vertex] = VertexColor::VISITED;
        sortResult.push_front(vertex);
    }

    return true;
}