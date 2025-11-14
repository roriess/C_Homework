#include <stdio.h>
#include <string.h>

#define MAX_LEN 100

int main()
{
    char string[MAX_LEN];

    printf("Enter an expression containing parentheses: ");
    fgets(string, MAX_LEN, stdin);
    string[strcspn(string, "\n")] = '\0';


    int openingParentheses = 0;
    int lenString = strlen(string);

    for (int i = 0; i < lenString; i++) {
        if (string[i] == '(') {
            openingParentheses++;
        } else if (string[i] == ')') {
            if (openingParentheses != 0) {
                openingParentheses--;
            } else {
                printf("The balance of parentheses in the line is broken");
                return 1;
            }
        }
    }

    if (openingParentheses == 0) {
        puts("The balance of parentheses in the line is maintained");
    } else {
        puts("The balance of parentheses in the line is broken");
        return 1;
    }
    return 0;
}