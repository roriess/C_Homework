#include <stdbool.h>
#include <stdio.h>

int main(void)
{
    int n, size;
    printf("Enter a size of array: ");
    scanf("%d", &size);

    printf("Enter numbers (1 number - 1 line), 0 - end of input:\n");
    // zero is not an element of the list.

    int arr[size];
    scanf("%d", &n);

    int i = 0;
    while (n != 0 && i <= size) {
        arr[i++] = n;
        scanf("%d", &n);
    }

    int res[size];
    int j = 0;
    for (int e = 0; e < i; e++) {
        bool flag = 0;
        for (int r = 0; r < i; r++) {
            if (e == r)
                continue;
            if (arr[e] == arr[r] + 1 || arr[e] == arr[r] - 1) {
                flag = 1;
                break;
            }
        }
        if (!flag)
            res[j++] = arr[e];
    }

    printf("Elements without a pair: ");
    for (int q = 0; q < j; q++)
        printf("%d ", res[q]);

    printf("\n");
    return 0;
}