#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

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

const int* spacesCount(Data* data)
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

    for (int i = 0; i < data->linesCount; i++)
        printf("%s\n", data->data[i]);

    return data;
}
