#pragma once

#include <graphs/Generator/Generator.hpp>

template <typename GraphImplementation>
class OnlyEulerAndNotHamiltonGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        GraphImplementation graph(verticesNumber);
        int edgesNumber = this->getEdgesNumberFromSaturation(graph, saturationPercents);
        this->fillWithSmallestHamiltonCycle(graph, verticesNumber - 1);
        this->fillWithBestMatchedEulerCycle(graph, verticesNumber - 1, edgesNumber - verticesNumber + 1);

        return graph;
    }
};