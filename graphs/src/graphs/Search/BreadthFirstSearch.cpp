#include <list>
#include <queue>
#include <vector>

#include <graphs/Graph/Graph.hpp>
#include <graphs/Search/Search.hpp>
#include <graphs/Search/BreadthFirstSearch.hpp>

std::list<int> BreadthFirstSearch::search(Graph& graph, int startVertex) const {
    std::list<int> searchResult;
    std::queue<int> adjacentVertices;
    std::vector<bool> visitedVertices(graph.getVerticesNumber(), false);

    adjacentVertices.push(startVertex);
    while (!adjacentVertices.empty()) {
        auto currentVertex = adjacentVertices.front();
        adjacentVertices.pop();
        
        if (!visitedVertices[currentVertex]) {
            visitedVertices[currentVertex] = true;
            searchResult.push_back(currentVertex);

            for (auto v : graph.getSuccessors(currentVertex)) {
                if (!visitedVertices[v]) {
                    adjacentVertices.push(v);
                }
            }
        }
    }

    return searchResult;
}
