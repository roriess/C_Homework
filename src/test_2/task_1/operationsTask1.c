#include "operationsTask1.h"

int binToInt(bool arr[], int size)
{
    int res = 0;
    for (int i = 0; i < size; i++)
        res = res * 2 + arr[i];

    return res;
}

void shiftToLeft(bool arr[], int size)
{
    bool first = arr[0];
    for (int i = 0; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = first;
}