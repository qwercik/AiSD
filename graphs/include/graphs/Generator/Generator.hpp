#pragma once

#include <graphs/Graph.hpp>

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
};