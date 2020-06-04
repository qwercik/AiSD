#pragma once

#include <list>
#include <cstdlib>

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

        // Edges should not be bigger then graph.maxEdges()
    void fillRandom(Graph& graph, int verticesNumber, int edges) {
        while (edges > 0) {
            int startVertex = rand() % verticesNumber;
            int endVertex = rand() % verticesNumber;
            
            if (startVertex != endVertex && !graph.containsEdge(startVertex, endVertex)) {
                graph.addEdge(startVertex, endVertex);
                edges--;
            }
        }
    }


    // Only for n >= 4
    template <bool directed = false>
    void fill(Graph& graph, int edges) {
        int verticesNumber = graph.getVerticesNumber();
        int startVertex = 0;
        int endVertex = 0;

        for (int i = 0; i < edges; ++i) {
            if (startVertex == endVertex) {
                endVertex++;
            }

            if (endVertex == verticesNumber) {
                startVertex++;
                endVertex = directed ? 0 : startVertex + 1;
            }

            graph.addEdge(startVertex, endVertex);
            endVertex++;
        }
    }


    // Saturation percents should be enough!!!
    // TODO: calculate minimum satuartion and raise exception in case of problems
    template <typename T>
    T generateHamilton(int verticesNumber, int saturationPercents = 50) {
        T graph(verticesNumber);

        // edges should >= verticesNumber
        int edges = graph.maxEdges() * (saturationPercents / 100.);
        
        std::vector<bool> visited(verticesNumber, false);
        int predecessor = 0;
        visited[predecessor] = true;
        for (int i = 0; i < verticesNumber - 1; ++i) {
            int successor;
            do {
                successor = rand() % verticesNumber;
            } while (visited[successor]);
            visited[successor] = true;
            //std::cerr << "[DBG] dodaję krawędź " << predecessor << " -> " << successor << '\n';
            graph.addEdge(predecessor, successor);
            predecessor = successor;
        }

        graph.addEdge(predecessor, 0);
        fillRandom(graph, verticesNumber, edges - verticesNumber);
        return graph;
    }

    bool fillEulerBruteForce(UndirectedGraph& graph, int edgesNumber) {
        std::list<int> path;
        path.push_back(0);
        int currentVertex = 0;

        while (path.size() != edgesNumber + 1) {
            while (currentVertex == graph.getVerticesNumber()) {
                if (path.size() < 2) {
                    return false;
                }

                currentVertex = path.back();
                path.pop_back();
                graph.removeEdge(path.back(), currentVertex);

                currentVertex++;
            }

            if (path.empty()) {
                return false;
            }

            if (path.size() == edgesNumber) {
                currentVertex = 0;
                if (path.back() != currentVertex && !graph.containsEdge(path.back(), currentVertex)) {
                    graph.addEdge(path.back(), 0);
                    path.push_back(0);
                } else if (path.size() >= 2) {
                    currentVertex = path.back();
                    path.pop_back();
                    graph.removeEdge(path.back(), currentVertex);

                    currentVertex++;
                } else {
                    return false;
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