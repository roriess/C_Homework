#include "operations.c"

#include <stdio.h>

int main()
{
    Data* text = readText("input.csv");

    const int count = countColumns(text);
    const int* spaces = spacesCount(text);
    for (int i = 0; i < count; i++) {
        printf("%d\n", spaces[i]);
    }
    return 0;
}
