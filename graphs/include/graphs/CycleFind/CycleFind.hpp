#pragma once

#include <list>

#include <graphs/Graph/UndirectedGraph.hpp>

class CycleFind {
public:
    virtual std::list<int> find() = 0;
};