#pragma once

#include <graphs/Generator/Generator.hpp>

template <typename GraphImplementation>
class IterativeGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        GraphImplementation graph(verticesNumber);
        int edgesNumber = this->getEdgesNumberFromSaturation(graph, saturationPercents);
        this->fillIteratively(graph, verticesNumber, edgesNumber);
        
        return graph;
    }
};