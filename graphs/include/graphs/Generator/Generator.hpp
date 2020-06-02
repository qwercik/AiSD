#pragma once

#include <list>

#include <graphs/Graph.hpp>
#include <graphs/UndirectedGraph.hpp>

class Generator {
public:
    // Only for n >= 4
    template <typename T>
    T generate(int verticesNumber, int saturationPercents = 50) {
        T graph(verticesNumber);
        
        int startVertex = 0;
        int endVertex = 1;

        int edges = graph.maxEdges() * (saturationPercents / 100.);
        for (int i = 0; i < edges; ++i) {
             graph.addEdge(startVertex, endVertex);
             endVertex++;

             if (endVertex == verticesNumber) {
                 startVertex++;
                 endVertex = startVertex + 1;
             }
        }

        return graph;
    }

    bool fillEuler(UndirectedGraph& graph, int edgesNumber) {
        std::list<int> path;
        path.push_back(0);
        int currentVertex = 0;

        while (path.size() != edgesNumber + 1) {
            std::cerr << "[DBG] path = " << path << "| current = " << currentVertex << '\n';

            // Czy powinno to dziać się także dla głębszych wierzchołków?
            while (currentVertex == graph.getVerticesNumber()) {
                std::cerr << "[DBG] wywołałem się\n";
                currentVertex = path.back();
                path.pop_back();
                graph.removeEdge(path.back(), currentVertex);

                currentVertex++;
            }

            std::cerr << "[DBG] path.size() = " << path.size() << " | [DBG] path.empty() = " << path.empty() << "\n";

            if (path.empty()) {
                std::cerr << "Uwaga, kończem!\n";
                return false;
            }

            if (path.size() == edgesNumber) {
                if (path.back() != 0 && !graph.containsEdge(path.back(), 0)) {
                    graph.addEdge(path.back(), 0);
                    path.push_back(0);
                    // niepotrzebne, bo zaraz się skończy pętla
                    // ale do unifikacji spoko
                    currentVertex = 0;
                } else {
                    // czy tu trzeba usunąć krawędź?
                    currentVertex = path.back();
                    path.pop_back();
                    graph.removeEdge(path.back(), currentVertex);

                    currentVertex++;
                }
            } else {
                if (path.back() != currentVertex && !graph.containsEdge(path.back(), currentVertex)) {
                    graph.addEdge(path.back(), currentVertex);
                    path.push_back(currentVertex);
                    currentVertex = 0;
                } else {
                    currentVertex++;
                }
            }
        }

        return true;
    }
};