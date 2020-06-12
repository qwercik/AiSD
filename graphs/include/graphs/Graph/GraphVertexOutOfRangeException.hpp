#pragma once

#include <string>
#include <graphs/Graph/GraphException.hpp>

class GraphVertexOutOfRangeException : public GraphException {
public:
    GraphVertexOutOfRangeException(const std::string& message);
};
