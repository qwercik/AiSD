#include <string>

#include <graphs/Generator/GeneratorException.hpp>
#include <graphs/Generator/GeneratorSaturationOutOfRangeException.hpp>

GeneratorSaturationOutOfRangeException::GeneratorSaturationOutOfRangeException(const std::string& message) :
    GeneratorException(message)
{
}
