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

    int WhichKeyPressed(int eventKeyCode)
    {
        int result{ NULL };

        switch (eventKeyCode)
        {
        case '0':                   result = InternalProjectVariables::ID_BTN_ZERO;         break;
        case '1':                   result = InternalProjectVariables::ID_BTN_ONE;          break;
        case '2':                   result = InternalProjectVariables::ID_BTN_TWO;          break;
        case '3':                   result = InternalProjectVariables::ID_BTN_THREE;        break;
        case '4':                   result = InternalProjectVariables::ID_BTN_FOUR;         break;
        case '5':                   result = InternalProjectVariables::ID_BTN_FIVE;         break;
        case '6':                   result = InternalProjectVariables::ID_BTN_SIX;          break;
        case '7':                   result = InternalProjectVariables::ID_BTN_SEVEN;        break;
        case '8':                   result = InternalProjectVariables::ID_BTN_EIGHT;        break;
        case '9':                   result = InternalProjectVariables::ID_BTN_NINE;         break;
        case WXK_NUMPAD0:           result = InternalProjectVariables::ID_BTN_ZERO;         break;
        case WXK_NUMPAD1:           result = InternalProjectVariables::ID_BTN_ONE;          break;
        case WXK_NUMPAD2:           result = InternalProjectVariables::ID_BTN_TWO;          break;
        case WXK_NUMPAD3:           result = InternalProjectVariables::ID_BTN_THREE;        break;
        case WXK_NUMPAD4:           result = InternalProjectVariables::ID_BTN_FOUR;         break;
        case WXK_NUMPAD5:           result = InternalProjectVariables::ID_BTN_FIVE;         break;
        case WXK_NUMPAD6:           result = InternalProjectVariables::ID_BTN_SIX;          break;
        case WXK_NUMPAD7:           result = InternalProjectVariables::ID_BTN_SEVEN;        break;
        case WXK_NUMPAD8:           result = InternalProjectVariables::ID_BTN_EIGHT;        break;
        case WXK_NUMPAD9:           result = InternalProjectVariables::ID_BTN_NINE;         break;
        case WXK_ESCAPE:            result = InternalProjectVariables::ID_BTN_CLEAR;        break;
        case WXK_RETURN:            result = InternalProjectVariables::ID_BTN_CALCULATE;    break;
        case WXK_NUMPAD_ENTER:      result = InternalProjectVariables::ID_BTN_CALCULATE;    break;
        case '=':                   result = InternalProjectVariables::ID_BTN_CALCULATE;    break;
        case WXK_BACK:              result = InternalProjectVariables::ID_BTN_BACKSPACE;    break;
        // because in this case a more complex handler is needed
        //case '%':                   result = InternalProjectVariables::ID_BTN_PERCENT;      break;
        case WXK_NUMPAD_DECIMAL:    result = InternalProjectVariables::ID_BTN_POINT;        break;
        case '.':                   result = InternalProjectVariables::ID_BTN_POINT;        break;
        case WXK_NUMPAD_ADD:        result = InternalProjectVariables::ID_BTN_PLUS;         break;
        case '+':                   result = InternalProjectVariables::ID_BTN_PLUS;         break;
        case WXK_NUMPAD_SUBTRACT:   result = InternalProjectVariables::ID_BTN_MINUS;        break;
        case '-':                   result = InternalProjectVariables::ID_BTN_MINUS;        break;
        case WXK_NUMPAD_MULTIPLY:   result = InternalProjectVariables::ID_BTN_MULTIPLY;     break;
        case '*':                   result = InternalProjectVariables::ID_BTN_MULTIPLY;     break;
        case WXK_NUMPAD_DIVIDE:     result = InternalProjectVariables::ID_BTN_DIVIDE;       break;
        case '/':                   result = InternalProjectVariables::ID_BTN_DIVIDE;       break;
        default:
            result = NULL;
        }

        return result;
    }
} // namespace Utils
