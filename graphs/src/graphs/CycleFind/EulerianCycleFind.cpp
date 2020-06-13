#include <vector>
#include <list>

#include <graphs/CycleFind/CycleFind.hpp>
#include <graphs/CycleFind/CycleNotFoundException.hpp>
#include <graphs/CycleFind/EulerianCycleFind.hpp>
#include <graphs/Graph/UndirectedGraph.hpp>
#include <graphs/io.hpp>


EulerianCycleFind::EulerianCycleFind(UndirectedGraph& graph) :
    graph(graph),
    anyCycleExist(true)
{
    startingVertex = 0;
    for (; startingVertex < graph.getVerticesNumber(); ++startingVertex) {
        if (graph.getOutdegree(startingVertex) != 0) {
            break;
        }
    }

    if (startingVertex == graph.getVerticesNumber() || !checkExist()) {
        anyCycleExist = false;
        return;
    }

    currentVertex = startingVertex;
    path.push_back(startingVertex);
    successors.push_back(graph.getSuccessors(startingVertex));
    totalEdges = graph.totalEdges();
}

std::list<int> EulerianCycleFind::find() {
    if (!anyCycleExist || !findNextCycle()) {
        throw CycleNotFoundException("Next Eulerian cycle hasn\'t been found");
    }

    return path;
}

bool EulerianCycleFind::checkExist() {
    for (int i = 0; i < graph.getVerticesNumber(); ++i) {
        if (graph.getOutdegree(i) % 2 != 0) {
            return false;
        }
    }

    return true;
}

bool EulerianCycleFind::findNextCycle() {
    while (!path.empty() && !successors.empty()) {
        while (successors.back().empty()) {
            int successor = path.back();
            path.pop_back();
            successors.pop_back();

            if (path.empty() || successors.empty()) {
                return false;
            }
        
            int predecessor = path.back();
            graph.addEdge(predecessor, successor);
        }

        currentVertex = successors.back().front();
        successors.back().pop_front();

        if (path.size() == totalEdges) {
            return true;
        }

        graph.removeEdge(path.back(), currentVertex);
        path.push_back(currentVertex);
        successors.push_back(graph.getSuccessors(currentVertex));
    }

    return false;
}
