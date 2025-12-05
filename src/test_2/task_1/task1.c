#include "operationsTask1.c"

int main()
{
    bool arr[] = { 1, 1, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxNum = 0;
    for (int i = 0; i < size; i++) {
        int num = binToInt(arr, size);
        maxNum = (num > maxNum) ? num : maxNum;
        shiftToLeft(arr, size);
    }
    printf("%d", maxNum);
    return 0;
}