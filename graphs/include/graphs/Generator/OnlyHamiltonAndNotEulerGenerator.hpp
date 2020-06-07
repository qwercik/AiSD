#pragma once

#include <graphs/Generator/Generator.hpp>
#include <graphs/Generator/BothEulerAndHamiltonGenerator.hpp>

template <typename GraphImplementation>
class OnlyHamiltonAndNotEulerGenerator : public Generator<GraphImplementation> {
public:
    virtual GraphImplementation generate(int verticesNumber, int saturationPercents = 50) const override {
        BothEulerAndHamiltonGenerator<GraphImplementation> gen;

        auto graph = gen.generate(verticesNumber, saturationPercents);
        this->insertRandomEdgeToGraph(graph, verticesNumber);

        return graph;
    }
};