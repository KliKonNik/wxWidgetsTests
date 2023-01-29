#include "Operator.hpp"

Operator::Operator()
    : _oper(Operators::EMPTY)
{
}

Operator::Operator(Operators oper)
    : _oper(oper)
{
}

Operator::Operator(char oper)
{
    if (!Set(oper))
    {
        Clear();
    }
}

void Operator::Set(Operators oper)
{
    _oper = oper;
}

bool Operator::Set(char oper)
{
    switch (oper)
    {
    case '+': _oper = Operators::PLUS;      return true;
    case '-': _oper = Operators::MINUS;     return true;
    case '*': _oper = Operators::MULTIPLY;  return true;
    case '/': _oper = Operators::DIVIDE;    return true;
    }

    return false;
}

const Operator::Operators Operator::Get() const
{
    return _oper;
}

char Operator::GetChar() const
{
    switch (_oper)
    {
    case Operators::PLUS:       return '+';
    case Operators::MINUS:      return '-';
    case Operators::MULTIPLY:   return '*';
    case Operators::DIVIDE:     return '/';
    }
    return '\0';
}

bool Operator::IsEmpty() const
{
    return (_oper == Operators::EMPTY) ? true : false;
}

void Operator::Clear()
{
    _oper = Operators::EMPTY;
}
