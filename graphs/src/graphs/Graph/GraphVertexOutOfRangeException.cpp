#include <string>

#include <graphs/Graph/GraphVertexOutOfRangeException.hpp>


GraphVertexOutOfRangeException::GraphVertexOutOfRangeException(const std::string& message) :
    GraphException(message)
{
}
