#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

Data* readText(const char* fileName)
{
    FILE* f = fopen(fileName, "r");
    if (f == NULL) {
        printf("File not found.");
        exit(1);
    }

    int maxLines = 100;
    Data* data = malloc(sizeof(Data));
    data->data = malloc(sizeof(char*) * maxLines); // массив указателей на строки файла
    data->linesCount = 0;

    while (!feof(f)) {
        char* buffer = malloc(sizeof(char) * 100);
        const int readBytes = fscanf(f, "%[^\n]", buffer);
        if (readBytes < 0)
            break;

        if (data->linesCount >= maxLines) {
            maxLines *= 2;
            const char** temp = realloc(data, sizeof(char*) * maxLines);
            if (temp == NULL) {
                printf("Memory allocation error.\n");
                free(buffer);
                break;
            }
            data->data = temp;
        }

        data->data[data->linesCount] = buffer;
        data->linesCount++;

        // так как scanf читает до '\n', удалаяем оставшийся символ '\n'
        int c = fgetc(f);
        if (c != EOF && c != '\n')
            ungetc(c, f);
    }
    fclose(f);
    return data;
}

const int countColumns(Data* data)
{
    const char* str = data->data[0];
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ',')
            count++;
    }
    return count + 1;
}

const int* columnWidth(Data* data)
{
    int columnCount = countColumns(data);
    int* spaces = malloc(sizeof(int) * columnCount);
    for (int i = 0; i < columnCount; i++)
        spaces[i] = 0;

    for (int i = 0; i < data->linesCount; i++) {
        const char* str = data->data[i];
        int count = 0;
        int columnNumber = 0;
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] != ',') {
                count++;
            } else {
                if (count > spaces[columnNumber])
                    spaces[columnNumber] = count;
                columnNumber++;
                count = 0;
            }
        }
        if (count > spaces[columnNumber])
            spaces[columnNumber] = count;
    }
    return spaces;
}

const int tableWidth(Data* data, const int* countOfSpaces)
{
    int widthOfTable = 0;
    for (int i = 0; i < data->columnCount; i++)
        widthOfTable += countOfSpaces[i];
    return widthOfTable;
}

void tableTop(FILE* f, Data* data, const int* countOfSpaces)
{
    fprintf(f, "╔═");
    for (int i = 0; i < data->columnCount; i++) {
        for (int j = 0; j < countOfSpaces[i]; j++)
            fprintf(f, "═");
        if (i + 1 != data->columnCount)
            fprintf(f, "═╦═");
    }
    fprintf(f, "═╗\n");
}

void tableBottom(FILE* f, Data* data, const int* countOfSpaces)
{

    fprintf(f, "╚═");
    for (int i = 0; i < data->columnCount; i++) {
        for (int j = 0; j < countOfSpaces[i]; j++)
            fprintf(f, "═");
        if (i + 1 != data->columnCount)
            fprintf(f, "═⁠╧═");
    }
    fprintf(f, "═╝\n");
}

void dividersForTitle(FILE* f, Data* data, const int* countOfSpaces)
{
    fprintf(f, "╠═");
    for (int i = 0; i < data->columnCount; i++) {
        for (int j = 0; j < countOfSpaces[i]; j++)
            fprintf(f, "═");
        if (i + 1 != data->columnCount)
            fprintf(f, "═⁠╬═");
    }
    fprintf(f, "═╣\n");
}

void ordinaryDividers(FILE* f, Data* data, const int* countOfSpaces)
{
    fprintf(f, "╠─");
    for (int i = 0; i < data->columnCount; i++) {
        for (int j = 0; j < countOfSpaces[i]; j++)
            fprintf(f, "─");
        if (i + 1 != data->columnCount)
            fprintf(f, "─⁠┼─");
    }
    fprintf(f, "─╣\n");
}

void drawindLine(FILE* f, Data* data, const int* countOfSpaces, int flag, char* titleDivider, char* ordinaryDivider)
{
    for (int i = 0; i < data->linesCount; i++) {
        const char* str = data->data[i];
        fprintf(f, "║ ");
        int countWidth = 0, columnNumber = 0;
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[j] != ',') {
                fprintf(f, "%c", str[j]);
                countWidth++;
            } else {
                if (countWidth < countOfSpaces[columnNumber]) {
                    for (int k = 0; k < countOfSpaces[columnNumber] - countWidth; k++)
                        fprintf(f, " ");
                }
                fprintf(f, " ");
                if (flag) {
                    fprintf(f, "%s", titleDivider);
                } else {
                    fprintf(f, "%s", ordinaryDivider);
                }
                fprintf(f, " ");
                columnNumber++;
                countWidth = 0;
            }
        }
        if (countWidth < countOfSpaces[columnNumber]) {
            for (int k = 0; k < countOfSpaces[columnNumber] - countWidth; k++)
                fprintf(f, " ");
        }
        fprintf(f, " ║\n");

        if (i + 1 < data->linesCount) {
            if (!flag) {
                ordinaryDividers(f, data, countOfSpaces);
            } else {
                dividersForTitle(f, data, countOfSpaces);
                flag = 0;
            }
        }
    }
}

void dataFormatting(Data* data, const char* newFileName, const int* countOfSpaces)
{
    FILE* f = fopen(newFileName, "w");
    if (f == NULL) {
        printf("File not found or created.");
        exit(1);
    }

    const int widthOfTable = tableWidth(data, countOfSpaces);
    tableTop(f, data, countOfSpaces);
    drawindLine(f, data, countOfSpaces, 1, "║", "│");
    tableBottom(f, data, countOfSpaces);
}
