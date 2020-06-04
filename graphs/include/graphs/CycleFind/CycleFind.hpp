#pragma once

#include <list>

#include <graphs/UndirectedGraph.hpp>

class CycleFind {
public:
    virtual std::list<int> find() = 0;
};