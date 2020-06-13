#pragma once

#include <graphs/Generator/Generator.hpp>
#include <graphs/Generator/OnlyEulerianAndNotHamiltonianGenerator.hpp>

template <typename GraphImplementation>
class NeitherEulerianNorHamiltonianGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        OnlyEulerianAndNotHamiltonianGenerator<GraphImplementation> gen;

        auto graph = gen.generate(verticesNumber, saturationPercents);
        this->insertRandomEdgeToGraph(graph, verticesNumber - 1);

        return graph;
    }
};