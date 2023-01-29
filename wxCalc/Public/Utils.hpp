#pragma once

#include <string>

#include "Operand.hpp"
#include "Operator.hpp"

namespace Utils
{
    int DigitCount(const std::string& str);
    std::string StringSeparator(const std::string& str);
    std::string Despacer(const std::string& str);
    int WhatNumberPressed(int id_btn_value);
    char WhatOperatorPressed(int id_btn_value);
    Operand Calculate(const Operand& first, const Operator& oper, const Operand& second);
} // namespace Utils
