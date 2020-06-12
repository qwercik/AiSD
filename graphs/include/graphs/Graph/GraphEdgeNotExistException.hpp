#pragma once

#include <string>
#include <graphs/Graph/GraphException.hpp>

class GraphEdgeNotExistException : public GraphException {
public:
    GraphEdgeNotExistException(const std::string& message);
};

