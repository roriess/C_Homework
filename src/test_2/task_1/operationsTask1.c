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

int findMax(bool arr[], int size)
{
    int maxNum = 0;
    for (int i = 0; i < size; i++) {
        int num = binToInt(arr, size);
        maxNum = (num > maxNum) ? num : maxNum;
        shiftToLeft(arr, size);
    }

    return maxNum;
}