#pragma once

#include <graphs/Graph.hpp>
#include <graphs/random.hpp>

class Generator {
public:
    template <typename T>
    T generateIteratively(int verticesNumber, int saturationPercents = 50) {
        T graph(verticesNumber);
        int edgesNumber = getEdgesNumberFromSaturation(graph, saturationPercents);
        fillIteratively(graph, verticesNumber, edgesNumber);
        
        return graph;
    }

    template <typename T>
    T generateRandomly(int verticesNumber, int saturationPercents = 50) {
        T graph(verticesNumber);
        int edgesNumber = getEdgesNumberFromSaturation(graph, saturationPercents);
        fillRandomly(graph, verticesNumber, edgesNumber);
        
        return graph;
    }

protected:
    /**
     * Function returns how many edges graph should contain
     * <saturationPercents> describe existing edges to max edges (in complete graph) proportion
     */
    int getEdgesNumberFromSaturation(Graph& graph, int saturationPercents = 50) {
        return graph.maxEdges() * (saturationPercents / 100.0);
    }


    /**
     * Function insert edges iteratively (first all edges incident with first vertex, next all edges incident with second etc.)
     */
    void fillIteratively(Graph& graph, int verticesNumber, int edgesNumber) {
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
    void fillRandomly(Graph& graph, int verticesNumber, int edgesNumber) {
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
    void insertRandomEdgeToGraph(UndirectedGraph& graph, int verticesNumber) {
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
    bool polygonCanBeInsertedToGraph(Graph& graph, std::array<int, N>& polygon) {
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
    void polygonInsert(Graph& graph, std::array<int, N> polygon) {
        for (int index = 1; index < N; ++index) {
            graph.addEdge(polygon[index - 1], polygon[index]);
        }
        graph.addEdge(polygon[N - 1], polygon[0]);
    }
};