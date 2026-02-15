#include "operations.h"
#include <stdio.h>
#include <stdlib.h>

void readAndAddText(char* newFileName, char* oldFileName)
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
    }
    fclose(oldFile);
    fclose(newFile);
}
