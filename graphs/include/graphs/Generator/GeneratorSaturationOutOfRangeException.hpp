#pragma once

#include <string>
#include <stdexcept>

#include <graphs/Generator/GeneratorException.hpp>

class GeneratorSaturationOutOfRangeException : public GeneratorException {
public:
    GeneratorSaturationOutOfRangeException(const std::string& message);
};
