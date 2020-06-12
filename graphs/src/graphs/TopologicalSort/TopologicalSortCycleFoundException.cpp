#include <string>

#include <graphs/TopologicalSort/TopologicalSortException.hpp>
#include <graphs/TopologicalSort/TopologicalSortCycleFoundException.hpp>

TopologicalSortCycleFoundException::TopologicalSortCycleFoundException(const std::string& message) :
    TopologicalSortException(message)
{
}

