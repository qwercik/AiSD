#pragma once

#include <string>

#include <graphs/TopologicalSort/TopologicalSortException.hpp>

class TopologicalSortCycleFoundException : public TopologicalSortException {
public:
    TopologicalSortCycleFoundException(const std::string& message);
};
