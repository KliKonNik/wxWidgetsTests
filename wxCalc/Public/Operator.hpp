#pragma once

class Operator
{
public:
    enum class Operators
    {
        PLUS,
        MINUS,
        MULTIPLY,
        DIVIDE,
        EMPTY
    };

    Operator();
    Operator(Operators oper);
    Operator(char oper);

    void Set(Operators oper);
    bool Set(char oper);
    const Operators Get() const;
    char GetChar() const;
    bool IsEmpty() const;
    void Clear();

private:
    Operators _oper;
};
