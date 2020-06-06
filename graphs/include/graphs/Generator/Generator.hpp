#pragma once

#include <graphs/Graph.hpp>

class Generator {
public:

    /**
     * Function returns how many edges graph should contain
     * <saturationPercents> describe existing edges to max edges (in complete graph) proportion
     */
    int getEdgesNumberFromSaturation(Graph& graph, int saturationPercents = 50) {
        return graph.maxEdges() * (saturationPercents / 100.0);
    }

        // Edges should not be bigger then graph.maxEdges()

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
};