#include <stdexcept>
#include <string>

#include <graphs/TopologicalSort/TopologicalSortException.hpp>

TopologicalSortException::TopologicalSortException(const std::string& message) :
    std::runtime_error(message)
{
}
