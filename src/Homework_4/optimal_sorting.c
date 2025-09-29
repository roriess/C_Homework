#include <stdio.h>
#include <string.h>

#include "optimal_sorting.h"

#define MAX_LEN 100

void strToArr(const char* str, int* arr) 
{
    int currentNum = 0;
    int numCount = 0;
    size_t lengthStr = strlen(str);

    while (*str) {
        if (*str >= '0' && *str <= '9') {
            currentNum = currentNum * 10 + (*str - '0');
        } else if (currentNum > 0) {
            arr[numCount++] = currentNum;
            currentNum = 0;
        }
        str++;
    }
    if (currentNum > 0)
        arr[numCount++] = currentNum;
}


void bubbleSort(int arr[], int lengthArr) {
    for (int i = 0; i < lengthArr - 1; i++) {
        for (int j = 0; j < lengthArr - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    char str[MAX_LEN];
    scanf("%99[^\n]", str);

    int arr[MAX_LEN], originalArr[MAX_LEN];

    strToArr(str, arr);
    
    int lengthArr = 0;
    while (arr[lengthArr])
        lengthArr++;

    memcpy(originalArr, arr, sizeof(int) * lengthArr);

    bubbleSort(arr, lengthArr);

    int count = 0;
    for (int i = 0; i < lengthArr; i++) {
        if (originalArr[i] != arr[i])
            count++;
    }

    printf("%d", count);
    return 0;
}
