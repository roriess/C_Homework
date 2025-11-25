#include "checkingForASymbol.h"

int priority(char element)
{
    switch (element) {
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default:
        return 0;
    }
}

bool isLeftBracket(char element)
{
    return element == '(';
}

bool isRightBracket(char element)
{
    return element == ')';
}

bool isOperator(char element)
{
    return (element == '*' || element == '/' || element == '+' || element == '-');
}
