#pragma once

#include <list>
#include <array>
#include <vector>
#include <cstdlib>
#include <algorithm>

#include <graphs/Generator/Generator.hpp>
#include <graphs/DirectedGraph.hpp>
#include <graphs/random.hpp>

class DirectedGraphGenerator : public Generator {
public:
    // Only for n >= 4
    void fill(DirectedGraph& graph, int verticesNumber, int edgesNumber) {
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
};