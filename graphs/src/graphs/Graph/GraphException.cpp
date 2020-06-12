#include <string>
#include <stdexcept>

#include <graphs/Graph/GraphException.hpp>

GraphException::GraphException(const std::string& message) :
    std::runtime_error(message)
{
}