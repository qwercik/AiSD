#pragma once

#include <graphs/Generator/Generator.hpp>

template <typename GraphImplementation>
class RandomGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        GraphImplementation graph(verticesNumber);
        int edgesNumber = this->getEdgesNumberFromSaturation(graph, saturationPercents);
        this->fillRandomly(graph, verticesNumber, edgesNumber);
        
        return graph;
    }
};