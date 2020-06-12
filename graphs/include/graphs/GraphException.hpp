#pragma once

#include <string>
#include <stdexcept>

class GraphException : public std::runtime_error {
public:
    GraphException(const std::string& message);
};

class GraphVertexOutOfRangeException : public GraphException {
public:
    GraphVertexOutOfRangeException(const std::string& message);
};

class GraphEdgeNotExistException : public GraphException {
public:
    GraphEdgeNotExistException(const std::string& message);
};
