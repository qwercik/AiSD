#include <string>
#include <stdexcept>

#include <graphs/CycleFind/CycleFindException.hpp>
#include <graphs/CycleFind/CycleNotFoundException.hpp>

CycleNotFoundException::CycleNotFoundException(const std::string& message) :
    CycleFindException(message)
{
}
