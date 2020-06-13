#pragma once

#include <graphs/Generator/Generator.hpp>

template <typename GraphImplementation>
class OnlyEulerianAndNotHamiltonianGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        GraphImplementation graph(verticesNumber);
        int edgesNumber = this->getEdgesNumberFromSaturation(graph, saturationPercents);
        this->fillWithSmallestHamiltonianCycle(graph, verticesNumber - 1);
        this->fillWithBestMatchedEulerianCycle(graph, verticesNumber - 1, edgesNumber - verticesNumber + 1);

        return graph;
    }
};