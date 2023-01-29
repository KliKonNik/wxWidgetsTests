#include "Utils.hpp"
#include "InternalProjectVariables.hpp"

namespace Utils
{
    int DigitCount(const std::string& str)
    {
        int result{ 0 };

        for (char symbol : str)
        {
            if (isdigit(symbol))
            {
                ++result;
            }
        }

        return result;
    }

    std::string StringSeparator(const std::string& str)
    {
        std::string result;
        size_t indexPoint = (str.find_first_of('.') != std::string::npos) ? str.find_first_of('.') : str.size();
        int indexBeginNumber = (str[0] == '-') ? 1 : 0;

        for (int i = indexPoint - 1; i >= indexBeginNumber; --i)
        {
            result += str[i];
            
            if (((indexPoint - i) % 3 == 0) && i != indexBeginNumber)
            {
                result += ' ';
            }
        }

        std::reverse(result.begin(), result.end());

        result.append(str.begin() + indexPoint, str.end());

        if (indexBeginNumber)
        {
            result = '-' + result;
        }

        return result;
    }

    std::string Despacer(const std::string& str)
    {
        std::string result{ str };

        result.erase(remove(result.begin(), result.end(), ' '), result.end());

        return result;
    }

    int WhatNumberPressed(int id_btn_value)
    {
        using namespace InternalProjectVariables;
        int result{ 0 };
        switch (id_btn_value)
        {
        case ID_BTN_ZERO:   result = 0; break;
        case ID_BTN_ONE:    result = 1; break;
        case ID_BTN_TWO:    result = 2; break;
        case ID_BTN_THREE:  result = 3; break;
        case ID_BTN_FOUR:   result = 4; break;
        case ID_BTN_FIVE:   result = 5; break;
        case ID_BTN_SIX:    result = 6; break;
        case ID_BTN_SEVEN:  result = 7; break;
        case ID_BTN_EIGHT:  result = 8; break;
        case ID_BTN_NINE:   result = 9; break;
        }
        return result;
    }

    char WhatOperatorPressed(int id_btn_value) 
    {
        using namespace InternalProjectVariables;
        char result;

        switch (id_btn_value)
        {
        case ID_BTN_PLUS:       result = '+'; break;
        case ID_BTN_MINUS:      result = '-'; break;
        case ID_BTN_MULTIPLY:   result = '*'; break;
        case ID_BTN_DIVIDE:     result = '/'; break;
        default:
            result = '\0';
        }

        return result;
    }

    Operand Calculate(const Operand& first, const Operator& oper, const Operand& second)
    {
        Operand answer;
        switch (oper.Get())
        {
        case Operator::Operators::PLUS:
            answer.SetValue(first.GetValue() + second.GetValue());
            break;
        case Operator::Operators::MINUS:
            answer.SetValue(first.GetValue() - second.GetValue());
            break;
        case Operator::Operators::MULTIPLY:
                answer.SetValue(first.GetValue() * second.GetValue());
                break;
        case Operator::Operators::DIVIDE:
            if (second.GetValue() != 0.0)
            {
                answer.SetValue(first.GetValue() / second.GetValue());
            }
            else
            {
                answer.SetEmpty(true);
            }
            break;
        }

        return answer;
    }
} // namespace Utils
