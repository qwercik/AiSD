#pragma once

#include <list>
#include <array>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <graphs/Graph.hpp>
#include <graphs/UndirectedGraph.hpp>
#include <graphs/random.hpp>

class UndirectedGraphGenerator {
public:
    /**
     * Function returns how many edges graph should contain
     * <saturationPercents> describe existing edges to max edges (in complete graph) proportion
     */
    int getEdgesNumberFromSaturation(UndirectedGraph& graph, int saturationPercents = 50) {
        return graph.maxEdges() * (saturationPercents / 100.0);
    }

    /**
     * Function assumes that graph has no edges and at least one vertex
     * It fill graph with randomly generated cycle of <verticesNumber> edges
     * It return number of filled edges, so it's <verticesNumber>
     */
    int fillWithSmallestHamiltonCycle(UndirectedGraph& graph, int verticesNumber) {
        const int startingVertex = 0;
        
        std::vector<bool> visited(verticesNumber, false);
        int predecessor = startingVertex;
        visited[startingVertex] = true;
        int successor;

        for (int index = 0; index < verticesNumber - 1; ++index) {
            do {
                successor = rand() % verticesNumber;
            } while (visited[successor]);
            
            graph.addEdge(predecessor, successor);
            visited[successor] = true;
            predecessor = successor;
        }

        graph.addEdge(predecessor, successor);
    }

    /**
     * Function assumes that every graph vertice has even degree (isolated vertices allowed)
     * It's not possible to create Euler graph for every (<verticesNumber>, <edgesNumber>) pair
     * So the function try to do it best it's possible (an absolute error should be 0 or 1)
     * Function returns number of inserted edges
     */
    int fillWithBestMatchedEulerCycle(UndirectedGraph& graph, int verticesNumber, int edgesNumber) {
        int insertedEdgesCounter = 0;
        for (; insertedEdgesCounter < edgesNumber - 1; insertedEdgesCounter += 3) {
            std::array<int, 3> triangle;
            do {
                triangle = randomIntegers<3>(0, verticesNumber);
            } while (!polygonCanBeInsertedToGraph<3>(graph, triangle));
            
            polygonInsert<3>(graph, triangle);
        }

        return insertedEdgesCounter;
    }

    /**
     * Polygon is nothing else than cycle
     * If any of edges described by polygon exists in graph, function will return false
     * Otherwise it will return true
     */
    template <int N>
    bool polygonCanBeInsertedToGraph(UndirectedGraph& graph, std::array<int, N>& polygon) {
        for (int index = 1; index < N; ++index) {
            if (graph.containsEdge(polygon[index - 1], polygon[index])) {
                return false;
            }
        }

        return !graph.containsEdge(polygon[N - 1], polygon[0]);
    }

    /**
     * Function assumes that polygonCanBeInsertedToGraph() returns true for graph
     */
    template <int N>
    void polygonInsert(UndirectedGraph& graph, std::array<int, N> polygon) {
        for (int index = 1; index < N; ++index) {
            graph.addEdge(polygon[index - 1], polygon[index]);
        }
        graph.addEdge(polygon[N - 1], polygon[0]);
    }



    // Only for n >= 4
    template <typename T>
    T generate(int verticesNumber, int saturationPercents = 50) {
        T graph(verticesNumber);
        
        int startVertex = 0;
        int endVertex = 1;

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
    void fillHamilton(UndirectedGraph& graph, int verticesNumber, int saturationPercents = 50) {
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

            graph.addEdge(predecessor, successor);
            predecessor = successor;
        }

        graph.addEdge(predecessor, 0);
        fillRandom(graph, verticesNumber, edges - verticesNumber);
    }

    bool fillEulerBruteForce(UndirectedGraph& graph, int verticesNumber, int edgesNumber) {
        std::list<int> path;
        path.push_back(0);
        int currentVertex = 0;

        while (path.size() != edgesNumber + 1) {
            while (currentVertex == verticesNumber) {
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

    void fillEulerWithSmallestNumberOfEdges(UndirectedGraph& graph, int verticesNumber) {

    }
};