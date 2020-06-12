#pragma once

#include <string>
#include <stdexcept>

class CycleFindException : public std::runtime_error {
public:
    CycleFindException(const std::string& message);
};
