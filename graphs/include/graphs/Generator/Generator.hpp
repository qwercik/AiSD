#pragma once

#include <graphs/Graph.hpp>

template <typename T>
class Generator {
public:
    // Only for n >= 4
    T generate(int verticesNumber) {
        T graph(verticesNumber);    
        
        int startVertex = 0;
        int endVertex = 1;

        int edges = verticesNumber * (verticesNumber - 1) / 4;
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