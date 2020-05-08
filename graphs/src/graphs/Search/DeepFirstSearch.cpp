#include <list>
#include <vector>

#include <graphs/Graph.hpp>
#include <graphs/Search/Search.hpp>
#include <graphs/Search/DeepFirstSearch.hpp>

std::list<int> DeepFirstSearch::search(Graph& graph, int startVertex) const {
    std::list<int> searchResult;
    std::vector<bool> visitedVertices(graph.getVerticesNumber(), false);

    searchBackend(graph, startVertex, visitedVertices, searchResult);
    return searchResult;
}

void DeepFirstSearch::searchBackend(Graph& graph, int currentVertex, std::vector<bool>& visitedVertices, std::list<int>& searchResult) const {
    if (!visitedVertices[currentVertex]) {
        searchResult.push_back(currentVertex);
        visitedVertices[currentVertex] = true;

        for (auto v : graph.getAdjacentVertices(currentVertex)) {
            searchBackend(graph, v, visitedVertices, searchResult);
        }
    }
}
