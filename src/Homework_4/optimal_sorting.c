#include <stdio.h>
#include <string.h>

#include "optimal_sorting.h"

#define MAX_LEN 100

void strToArr(const char* str, int* arr) 
{
    int currentNum = 0;
    int numCount = 0;
    int lengthStr = strlen(str);

    for (int i = 0; i < lengthStr; i++) {
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


void optimal_sorting(int* arr, int lengthArr) 
{
    for (int j = 0; j < lengthArr; j++) {
        int lowestValueIndex = j;

        for (int k = j + 1; k < lengthArr; k++) {
            if (arr[k] < arr[lowestValueIndex]) 
                lowestValueIndex = k;
        }
        int temp = arr[j];
        arr[j] = arr[lowestValueIndex];
        arr[lowestValueIndex] = temp;
    }
}


int main() 
{
    char str[MAX_LEN];
    scanf("%99[^\n]", str);

    int arr[MAX_LEN];
    memset(arr, 0, sizeof(arr));

    strToArr(str, arr);
    
    
    int lengthArr = 0;
    while (lengthArr < MAX_LEN && arr[lengthArr] != 0)
        lengthArr++;

    int originalArr[lengthArr];
    for (int j = 0; j < lengthArr; j++)
        originalArr[j] = arr[j];

    optimal_sorting(arr, lengthArr);

    int count = 0;

    for (int i = 0; i < lengthArr; i++) {
        if (originalArr[i] != arr[i])
            count++;
    }

    printf("%d", count);
    return 0;
}
