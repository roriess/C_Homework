#include "operations.c"

#include <stdio.h>

void main()
{
    Data* text = readText("input.csv");

    text->columnCount = countColumns(text);
    const int* widthOfColumn = columnWidth(text);
    dataFormatting(text, "output.txt", widthOfColumn);
}
