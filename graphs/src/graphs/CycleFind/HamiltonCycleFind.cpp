#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/CycleFind/CycleFindException.hpp>
#include <graphs/CycleFind/HamiltonCycleFind.hpp>
#include <graphs/UndirectedGraph.hpp>
#include <graphs/io.hpp>


HamiltonCycleFind::HamiltonCycleFind(UndirectedGraph& graph) :
    graph(graph),
    visited(graph.getVerticesNumber(), false),
    currentVertex(START_VERTEX)
{
    path.push_back(currentVertex);
    successors.push_back(graph.getSuccessors(currentVertex));
    visited[currentVertex] = true;
}

std::list<int> HamiltonCycleFind::find() {
    if (!findNextCycle()) {
        throw CycleNotFoundException("Next Hamilton cycle hasn\'t been found");
    }

    return path;
}

bool HamiltonCycleFind::findNextCycle() {
    while (!path.empty() && !successors.empty()) {
        while (successors.back().empty()) {
            visited[path.back()] = false;
            path.pop_back();
            successors.pop_back();

            if (path.empty() || successors.empty()) {
                return false;
            }
        }

        currentVertex = successors.back().front();
        successors.back().pop_front();

        if (path.size() == graph.getVerticesNumber() && currentVertex == START_VERTEX) {
            return true;
        }
        
        if (!visited[currentVertex]) {
            visited[currentVertex] = true;
            path.push_back(currentVertex);
            successors.push_back(graph.getSuccessors(currentVertex));
        }
    }

    return false;
}
