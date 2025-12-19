#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 10

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
