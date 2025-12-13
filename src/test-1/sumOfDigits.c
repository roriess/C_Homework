#include <stdio.h>

int sumBin(int a)
{
    int sum = 0;
    while (a > 0) {
        sum += a % 2;
        a /= 2;
    }
    return sum;
}

int main(void)
{
    int a = 1;
    int b = 2;

    int sumA = sumBin(a);
    int sumB = sumBin(b);
    if (sumA == sumB) {
        printf("The sum of digits in binary notation is the same.\n");
    } else {
        if (sumA > sumB)
            printf("%d\n", a);
        if (sumB > sumA)
            printf("%d\n", b);
    }

    return 0;
}