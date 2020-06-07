#pragma once

#include <graphs/Generator/Generator.hpp>
#include <graphs/Generator/OnlyEulerAndNotHamiltonGenerator.hpp>

template <typename GraphImplementation>
class NeitherEulerNorHamiltonGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        OnlyEulerAndNotHamiltonGenerator<GraphImplementation> gen;

        auto graph = gen.generate(verticesNumber, saturationPercents);
        this->insertRandomEdgeToGraph(graph, verticesNumber - 1);

        return graph;
    }
};