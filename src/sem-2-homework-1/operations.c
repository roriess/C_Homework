#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

int countCommas(const char* str)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',')
            count++;
    }
    return count + 1;
}

int* spacesCount(const char* str, int columnCount)
{
    int* data = malloc(sizeof(int) * columnCount);
    int count = 0;
    int columnNumber = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ',') {
            count++;
        } else {
            if (count > data[columnNumber])
                data[columnNumber] = count;
            columnNumber++;
            count = 0;
        }
    }
    for (int i = 0; i < columnCount; i++)
        printf("%d", data[i]);

    return data;
}

char* stringFormatting(char* str, const int* data)
{
}

void readAndAddText(char* newFileName, const char* oldFileName)
{
    FILE* oldFile = fopen(oldFileName, "r");
    if (oldFile == NULL) {
        printf("File not found.");
        return;
    }

    FILE* newFile = fopen(newFileName, "w");
    if (newFile == NULL) {
        printf("File not created or found.");
        return;
    }

    int linesRead = 0;
    int columnCount;
    int firstLine = 1; // для подсчета количества столбцов
    while (!feof(oldFile)) {
        char* buffer = malloc(sizeof(char) * 100);
        const int readBytes = fscanf(oldFile, "%[^\n]", buffer);
        if (readBytes < 0)
            break;

        // так как scanf читает до '\n', удалаяем оставшийся символ '\n'
        int c = fgetc(oldFile);
        if (c != EOF && c != '\n')
            ungetc(c, oldFile);

        fprintf(newFile, "%s\n", buffer);
        linesRead++;

        if (firstLine) {
            columnCount = countCommas(buffer) + 1;
            firstLine = 0;
        }
    }
    fclose(oldFile);
    fclose(newFile);
}
