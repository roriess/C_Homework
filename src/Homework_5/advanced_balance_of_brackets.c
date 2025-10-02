#include <stdio.h>
#include <string.h>

#define MAX_LEN 100


int isInArray(char ch, char array[], int size) 
{
    for (int i = 0; i < size; i++) {
        if (array[i] == ch)
            return 1;
    }
    return 0;
}


int main()
{
    char string[MAX_LEN];

    printf("Enter an expression containing parentheses: ");
    fgets(string, MAX_LEN, stdin);
    string[strcspn(string, "\n")] = '\0';
    int lenString = strlen(string);

    char openingBrackets[] = "({[";
    char closingBrackets[] = ")}]";

    char stack[MAX_LEN];
    int number = 0;


    for (int i = 0; i < lenString; i++) {
        if (isInArray(string[i], openingBrackets, 3))
            stack[number++] = string[i];

        if (isInArray(string[i], closingBrackets, 3)) {
            if (number == 0) {
                puts("The balance of parentheses in the line is broken");
                return 1;
            }
            char *p = strchr(openingBrackets, stack[number - 1]);
            char *q = strchr(closingBrackets, string[i]);

            if (p != NULL && q != NULL && (p - openingBrackets) == (q - closingBrackets)) {
                number--;
            } else {
                puts("The balance of parentheses in the line is broken");
                return 1;
            }
        }
    }

    if (number == 0) {
        puts("The balance of parentheses in the line is maintained");
    } else {
        puts("The balance of parentheses in the line is broken");
        return 1;
    }
    return 0;
}
