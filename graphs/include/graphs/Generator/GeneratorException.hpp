#pragma once

#include <string>
#include <stdexcept>

class GeneratorException : public std::runtime_error {
public:
    GeneratorException(const std::string& message);
};