#include <string>
#include <stdexcept>

#include <graphs/CycleFind/CycleFindException.hpp>

CycleFindException::CycleFindException(const std::string& message) :
    std::runtime_error(message)
{
}

CycleNotFoundException::CycleNotFoundException(const std::string& message) :
    CycleFindException(message)
{
}
