#pragma once

#include <graphs/Generator/Generator.hpp>

template <typename GraphImplementation>
class BothEulerianAndHamiltonianGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        GraphImplementation graph(verticesNumber);
        int edgesNumber = this->getEdgesNumberFromSaturation(graph, saturationPercents);
        this->fillWithSmallestHamiltonianCycle(graph, verticesNumber);
        this->fillWithBestMatchedEulerianCycle(graph, verticesNumber, edgesNumber - verticesNumber);

        return graph;
    }
};