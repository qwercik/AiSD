#pragma once

#include <graphs/Generator/Generator.hpp>
#include <graphs/Generator/BothEulerianAndHamiltonianGenerator.hpp>

template <typename GraphImplementation>
class OnlyHamiltonianAndNotEulerianGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        BothEulerianAndHamiltonianGenerator<GraphImplementation> gen;

        auto graph = gen.generate(verticesNumber, saturationPercents);
        this->insertRandomEdgeToGraph(graph, verticesNumber);

        return graph;
    }
};