#pragma once

#include <string>
#include <stdexcept>

class GraphException : public std::runtime_error {
public:
    GraphException(const std::string& message);
};
