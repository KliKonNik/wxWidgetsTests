#pragma once

#include <string>

class Operand
{
public:
    Operand();
    Operand(long double dValue);
    const std::string GetString() const;
    void SetValue(long double value);
    const long double GetValue() const;
    void SetValueFromString(const std::string& str);
    void SetEmpty(bool boolValue);
    bool IsEmpty() const;

private:
    long double _dValue     { 0.0 };
    int         _precision  { 0 };
    bool        _empty      { true };
};
