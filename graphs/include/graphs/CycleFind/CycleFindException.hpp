#pragma once

#include <string>
#include <stdexcept>

class CycleFindException : public std::runtime_error {
public:
    CycleFindException(const std::string& message);
};

class CycleNotFoundException : public CycleFindException {
public:
    CycleNotFoundException(const std::string& message);
};