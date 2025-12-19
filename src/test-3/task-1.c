#include "operationsTask-1.h"
#include <stdio.h>

#define ARR_LEN 10

int main(void)
{
    printf("Введите номер команды: ");
    int number;
    scanf("%d", &number);
    int arr[ARR_LEN];

    while (number != 0) {
        if (number == 1) {
            fill_random(arr, ARR_LEN);
            printf("Массив заполнен случайными числами.\n");
            printArr(arr, ARR_LEN);
        }
        if (number == 2) {
            qsort(arr, ARR_LEN, sizeof(int), compare);
            printf("Массив отсортирован.\n");
            printArr(arr, ARR_LEN);
        }
        if (number == 3) {
            reverse(arr, ARR_LEN);
            printf("Массив развернут.\n");
            printArr(arr, ARR_LEN);
        }
        if (number == 4) {
            average(arr, ARR_LEN);
        }
        printf("Введите номер команды: ");
        scanf("%d", &number);
    }
    return 0;
}
