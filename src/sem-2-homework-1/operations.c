#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

char** readText(char* fileName)
{
    FILE* f = fopen(fileName, "r");
    if (f == NULL) {
        printf("File not found.");
        return NULL;
    }

    int maxLines = 100;
    char** data = malloc(sizeof(char*) * maxLines); // массив указателей на строки файла
    int linesRead = 0;

    while (!feof(f)) {
        char* buffer = malloc(sizeof(char) * 100);
        const int readBytes = fscanf(f, "%[^\n]", buffer);
        if (readBytes < 0)
            break;

        if (linesRead >= maxLines) {
            maxLines *= 2;
            char** temp = realloc(data, sizeof(char*) * maxLines);
            if (temp == NULL) {
                printf("Memory allocation error.\n");
                free(buffer);
                break;
            }
            data = temp;
        }

        data[linesRead] = buffer;
        linesRead++;

        // так как scanf читает до '/n', удалаяем оставшийся символ '/n'  
        int c = fgetc(f);
        if (c != EOF && c != '\n') 
            ungetc(c, f);
    }
    fclose(f);

    for (int i = 0; i < linesRead; i++)
        printf("%s\n", data[i]);

    return data;
}