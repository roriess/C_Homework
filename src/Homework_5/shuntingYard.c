#include <stdio.h>

#include <ctype.h>
#include <string.h>

#include "implementationOfStack.h"
#include "checkingForASymbol.h"

#define MAX_LEN 100

int main(void)
{
    char mathExpression[MAX_LEN];
    Stack* operators;
    initStack(operators);
    char result[MAX_LEN];
    int end = 0;

    printf("Enter an expression: ");
    fgets(mathExpression, MAX_LEN, stdin);
    mathExpression[strcspn(mathExpression, "\n")] = '\0';

    int size = strlen(mathExpression);
    for (int i = 0; i < size; i++) {
        char element = mathExpression[i];
        
        if (element == ' ')
            continue;

        if (isdigit(element)) {
            result[end++] = element;
            continue;
        }

        if (isLeftBracket(element)) {
            push(operators, element);
            continue;
        }

        if (isRightBracket(element)) {
            while (operators->top != -1 && !isLeftBracket(peek(operators)))
                result[end++] = pop(operators);

            if (operators->top != -1)
                pop(operators);

            continue;
        }

        if (isOperator(element)) {
            while (operators->top != -1 && priority(element) <= priority(peek(operators)))
                result[end++] = pop(operators);
            push(operators, element);
            continue;
        }

    while (operators->top != -1)
        result[end++] = pop(operators);

    result[end] = '\0';
    printf("%s\n", result);

    del(operators);
    return 0;
}
