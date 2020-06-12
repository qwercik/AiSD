#pragma once

#include <string>
#include <stdexcept>

#include <graphs/CycleFind/CycleFindException.hpp>

class CycleNotFoundException : public CycleFindException {
public:
    CycleNotFoundException(const std::string& message);
};