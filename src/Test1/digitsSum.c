#include <stdio.h>

int main(void)
{
    int maxSum = 0;
    int arr[] = {1234, 100, 123, 99, 8, 11111111, 981};

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        int sum = 0;
        int elm = arr[i];

        while (elm > 0) {
        sum += (elm % 10);
        elm /= 10;
        }
        if (sum > maxSum)
        maxSum = sum;
    }

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        int sum = 0;
        int elm = arr[i];

        while (elm > 0) {
        sum += (elm % 10);
        elm /= 10;
        }

        if (sum == maxSum)
        printf("%d ", arr[i]);
    }

    return 0;
}