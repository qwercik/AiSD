#include <string>

#include <graphs/Graph/GraphEdgeNotExistException.hpp>

GraphEdgeNotExistException::GraphEdgeNotExistException(const std::string& message) :
    GraphException(message)
{
}
