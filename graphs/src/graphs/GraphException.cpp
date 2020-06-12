#include <string>
#include <stdexcept>

#include <graphs/GraphException.hpp>

GraphException::GraphException(const std::string& message) :
    std::runtime_error(message)
{

}

GraphVertexOutOfRangeException::GraphVertexOutOfRangeException(const std::string& message) :
    GraphException(message)
{
}

GraphEdgeNotExistException::GraphEdgeNotExistException(const std::string& message) :
    GraphException(message)
{
}
