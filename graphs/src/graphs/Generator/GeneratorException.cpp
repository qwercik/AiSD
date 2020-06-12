#include <string>
#include <stdexcept>

#include <graphs/Generator/GeneratorException.hpp>

GeneratorException::GeneratorException(const std::string& message) :
    std::runtime_error(message)
{
}
