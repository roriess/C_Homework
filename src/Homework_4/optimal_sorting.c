#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "optimal_sorting.h"

#define MAX_LEN 100

void strToArr(const char* str, int* arr) 
{
    int currentNum = 0;
    int numCount = 0;
    size_t lengthStr = strlen(str);

    for (size_t i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            currentNum = currentNum * 10 + (str[i] - '0');
        } else if (currentNum > 0) {
            arr[numCount++] = currentNum;
            currentNum = 0;
        }
    }
    if (currentNum > 0)
        arr[numCount++] = currentNum;
}


static int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() 
{
    char str[MAX_LEN];
    scanf("%99[^\n]", str);

    int arr[MAX_LEN];
    memset(arr, 0, sizeof(arr));

    strToArr(str, arr);
    
    
    int lengthArr = 0;
    while (arr[lengthArr] != 0)
        lengthArr++;

    int originalArr[lengthArr];
    memcpy(originalArr, arr, sizeof(int) * lengthArr);

    qsort(arr, lengthArr, sizeof(int), compare_ints);

    int count = 0;
    for (int i = 0; i < lengthArr; i++) {
        if (originalArr[i] != arr[i])
            count++;
    }

    printf("%d", count);
    return 0;
}
