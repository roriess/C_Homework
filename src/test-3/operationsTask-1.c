#include "operationsTask-1.h"
#include <stdio.h>
#include <stdlib.h>

void reverse(int arr[], int len)
{
    for (int i = 0; i < len / 2; i++) {
        int tmp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = tmp;
    }
}

void average(int arr[], int len)
{
    int sum = 0;
    for (int i = 0; i < len; i++)
        sum += arr[i];

    printf("%f\n", (double)sum / len);
}

int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

void fill_random(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = rand() % 100;
}

void printArr(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}
