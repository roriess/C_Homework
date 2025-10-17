#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100


int st(int element, int s)
{
    int stElement = element;

    for (int i = 2; i <= st; i++) 
        stElement = stElement * element;

    return stElement;
{


char toBin(int element)
{
    char binElm[MAX_SIZE];
    int i = 0;

    while (element > 0) {
        binElm[i++] = (char)(element % 2) + binElm;
        element = element / 2;
    }
    return binElm;
}


int toInt(char binElement[])
{
    int intElement = 0;
    int stElm = 0;
    for (int i = 0; i < strlen(binElement); i++)
        stElm = st(2, i);
        intElement = intElement + (int)binElement[i]*stElm;

    return intElement;
}


void isPalindrom(char binElement[])
{
    int count = 0;
    int flag = 1;

    for (int i = 0; i < strlen(binElement) / 2; i++) {
        if (binElement[i] != binElement[strlen(binElement) / 2 - i + 1]) {
            flag = 0;
        }
    }

    if (flag == 1) {
        int element = toInt(binElement);
        printf("%d", element);
    } else {
        return;
    }
}
