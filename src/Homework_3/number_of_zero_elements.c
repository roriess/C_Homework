#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#define MAX_LEN 100

int main()
{
    char arr[MAX_LEN];

    printf("Enter the array elements: ");
    fgets(arr, MAX_LEN, stdin);
    arr[strcspn(arr, "\n")] = '\0';

    int count = 0;

    char* a = strtok(arr, " ");
    while (a != NULL) {
        int numberA = atoi(a);

        if (numberA == 0)
            count++;

        a = strtok(NULL, " ");
    }

    printf("Number of zero elements is %d", count);
    return 0;
}