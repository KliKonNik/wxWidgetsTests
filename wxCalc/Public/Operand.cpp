#include <sstream>
#include <iomanip>

#include "Operand.hpp"
#include "Utils.hpp"
#include "InternalProjectVariables.hpp"


Operand::Operand()
    : _dValue(0.0)
    , _precision(0)
    , _empty(true)
{
}

Operand::Operand(long double dValue)
{
    SetValue(dValue);
}

const std::string Operand::GetString() const
{
    std::stringstream result;

    if (_precision >= 0)
    {
        result << std::setiosflags(std::ios::fixed) << std::setprecision(_precision) << _dValue;
        result.str() = Utils::StringSeparator(result.str());
    }
    else
    {
        result << "Error value!";
    }

    return result.str();
}

void Operand::SetValue(long double value)
{
    _dValue = value;
    
    _precision = InternalProjectVariables::displayDigitsMaxLength - Utils::DigitCount(std::to_string(static_cast<int>(_dValue)));

    std::stringstream strToPrecision;

    strToPrecision << std::setiosflags(std::ios::fixed) << std::setprecision(_precision) << _dValue;

    for (int i = strToPrecision.str().size() - 1; i > 0; --i)
    {
        if (strToPrecision.str()[i] == '0')
        {
            --_precision;
        }
        else
        {
            break;
        }        
    }

    _empty = false;
}

const long double Operand::GetValue() const
{
    return _dValue;
}

void Operand::SetValueFromString(const std::string& str)
{
    std::string processingString{ str };

    processingString = Utils::Despacer(processingString);

    _dValue = std::stold(processingString);

    size_t pointIndex = processingString.find('.');

    if (pointIndex != std::string::npos)
    {
        // truncating trailing zeros
        size_t lastIndexNotZero{ pointIndex };
        for (int i = processingString.size() - 1; i > pointIndex; --i)
        {
            if (processingString[i] != '0')
            {
                lastIndexNotZero = i;
                break;
            }
        }
        
        _precision = processingString.substr(pointIndex + 1, lastIndexNotZero - pointIndex).size();
    }
    else
    {
        _precision  = 0;
    }
    
    _empty      = false;
}

void Operand::SetEmpty(bool boolValue)
{
    _empty = boolValue;
}

bool Operand::IsEmpty() const
{
    return _empty;
}
