#include <stdio.h>
#include <string.h>

#include "optimal_sorting.h"

#define MAX_LEN 100

void strToArr(const char* str, int* arr) 
{
    int currentNum = 0;
    int numCount = 0;
    size_t lengthStr = strlen(str);

    for (size_t i = 0; i < lengthStr; i++) {
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


void quicksort(int* arr, int firstElement, int lastElement) 
{
    if (firstElement >= lastElement)
        return;

    int pivot = arr[(firstElement + lastElement) / 2];
    int left = firstElement;
    int right = lastElement;

    do {
        while (arr[left] < pivot) 
            left++;

        while (arr[right] > pivot) 
            right--;
        
        if (left <= right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    } while(left <= right);

    quicksort(arr, firstElement, right);
    quicksort(arr, left, lastElement);
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
    memcpy(originalArr, arr, sizeof(int) * lengthArr);

    quicksort(arr, 0, lengthArr - 1);

    int count = 0;

    for (int i = 0; i < lengthArr; i++) {
        if (originalArr[i] != arr[i])
            count++;
    }

    printf("%d", count);
    return 0;
}
