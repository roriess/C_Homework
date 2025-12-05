#include "operationsTask1.h"

bool oneSymbol()
{
    bool arr[] = { 1 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxNum = findMax(arr, size);
    return maxNum == 1;
}

bool nothing()
{
    bool arr[] = {};
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxNum = findMax(arr, size);
    return maxNum == 0;
}

bool zero()
{
    bool arr[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int maxNum = findMax(arr, size);
    return maxNum == 0;
}
void runTests()
{
    bool result1 = oneSymbol() && nothing();
    bool result2 = zero();
    bool finalResul = result1 && result2;

    if (finalResul) {
        printf("Correct!\n");
    } else {
        if (!oneSymbol()) {
            printf("Error with one symbol\n");
        }
        if (!nothing()) {
            printf("Error with nothing\n");
        }
        if (!zero()) {
            printf("Error with a lot of zero symbols\n");
        }
    }
}