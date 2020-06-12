#pragma once

#include <stdexcept>
#include <string>

class TopologicalSortException : public std::runtime_error {
public:
    TopologicalSortException(const std::string& message);
};
