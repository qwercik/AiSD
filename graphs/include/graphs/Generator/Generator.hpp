#pragma once

#include <list>
#include <array>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <graphs/Graph/Graph.hpp>
#include <graphs/random.hpp>
#include <graphs/io.hpp>


template <typename GraphImplementation>
class Generator {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturatioNPercents = 50) const = 0;

protected:
    /**
     * Function returns how many edges graph should contain
     * <saturationPercents> describe existing edges to max edges (in complete graph) proportion
     */
    int getEdgesNumberFromSaturation(Graph& graph, int saturationPercents = 50) const {
        return graph.maxEdges() * (saturationPercents / 100.0);
    }


    /**
     * Function insert edges iteratively (first all edges incident with first vertex, next all edges incident with second etc.)
     */
    void fillIteratively(Graph& graph, int verticesNumber, int edgesNumber) const {
        int startVertex = 0;
        int endVertex = 1;

        for (int i = 0; i < edgesNumber; ++i) {
             graph.addEdge(startVertex, endVertex);
             endVertex++;

             if (endVertex == verticesNumber) {
                 startVertex++;
                 endVertex = startVertex + 1;
             }
        }
    }


    /**
     * Function fill graph with randomly generated <edgesNumber> edges
     */
    void fillRandomly(Graph& graph, int verticesNumber, int edgesNumber) const {
        while (edgesNumber > 0) {
            int startVertex = rand() % verticesNumber;
            int endVertex = rand() % verticesNumber;
            
            if (startVertex != endVertex && !graph.containsEdge(startVertex, endVertex)) {
                graph.addEdge(startVertex, endVertex);
                edgesNumber--;
            }
        }
    }

    /**
     * Make sure that graph is not complete
     */
    void insertRandomEdgeToGraph(UndirectedGraph& graph, int verticesNumber) const {
        std::array<int, 2> newEdge;
        do {
            newEdge = randomIntegers<2>(0, verticesNumber);
        } while (graph.containsEdge(newEdge[0], newEdge[1]));
        graph.addEdge(newEdge[0], newEdge[1]);
    }

    /**
     * Polygon is nothing else than cycle
     * If any of edges described by polygon exists in graph, function will return false
     * Otherwise it will return true
     */
    template <int N>
    bool polygonCanBeInsertedToGraph(Graph& graph, std::array<int, N>& polygon) const {
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
    void polygonInsert(Graph& graph, std::array<int, N>& polygon) const {
        for (int index = 1; index < N; ++index) {
            graph.addEdge(polygon[index - 1], polygon[index]);
        }
        graph.addEdge(polygon[N - 1], polygon[0]);
    }


    /**
     * Use this function very carefully!
     * It's possible to graph with given <verticesNumber> and <edgesNumber> cannot be Euler graph
     * In this case the function will be executing for some time (which can be really long)
     * And it's not guarantee it end with success
     */
    bool fillEulerUsingBactracking(UndirectedGraph& graph, int verticesNumber, int edgesNumber) const {
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

    /**
     * Function assumes that graph has no edges and at least one vertex
     * It fill graph with randomly generated cycle of <verticesNumber> edges
     * It return number of filled edges, so it's <verticesNumber>
     */
    int fillWithSmallestHamiltonCycle(UndirectedGraph& graph, int verticesNumber) const {
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

        graph.addEdge(predecessor, startingVertex);
        return verticesNumber;
    }
    

    /**
     * Function assumes that every graph vertice has even degree (isolated vertices allowed)
     * It's not possible to create Euler graph for every (<verticesNumber>, <edgesNumber>) pair
     * So the function try to do it best it's possible (an absolute error should be 0 or 1)
     * Function returns number of inserted edges
     */
    int fillWithBestMatchedEulerCycle(UndirectedGraph& graph, int verticesNumber, int edgesNumber) const {
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


    void fillHamilton(UndirectedGraph& graph, int verticesNumber, int edgesNumber) const {
        fillWithSmallestHamiltonCycle(graph, verticesNumber);
        fillRandomly(graph, verticesNumber, edgesNumber - verticesNumber);
    }
};