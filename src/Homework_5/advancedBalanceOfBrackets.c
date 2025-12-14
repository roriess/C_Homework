#include <stdio.h>
#include <string.h>

#include "implementationOfStack.h"

#define MAX_LEN 100


int isInArray(char ch, char array[], int size) 
{
    for (int i = 0; i < size; i++) {
        if (array[i] == ch)
            return 1;
    }
    return 0;
}


int main(void) 
{
    char string[MAX_LEN];
    Stack stack;
    initStack(&stack);

    printf("Enter an expression containing parentheses: ");
    fgets(string, MAX_LEN, stdin);
    string[strcspn(string, "\n")] = '\0';
    int lenString = strlen(string);

    char openingBrackets[] = "({[";
    char closingBrackets[] = ")}]";

    for (int i = 0; i < lenString; i++) {
        if (isInArray(string[i], openingBrackets, sizeof(openingBrackets) - 1))
            push(&stack, string[i]);

        if (isInArray(string[i], closingBrackets, sizeof(closingBrackets) - 1)) {
            if (stack.top == -1) {
                puts("The balance of parentheses in the line is broken");
                return 1;
            }

            char *p = strchr(openingBrackets, peek(&stack));
            char *q = strchr(closingBrackets, string[i]);

            if (p != NULL && q != NULL && (p - openingBrackets) == (q - closingBrackets)) {
                pop(&stack);
            } else {
                puts("The balance of parentheses in the line is broken");
                return 1;
            }
        }
    }
    if (stack.top == -1) {
        puts("The balance of parentheses in the line is maintained");
    } else {
        puts("The balance of parentheses in the line is broken");
        return 1;
    }

    del(&stack);
    return 0;
}
