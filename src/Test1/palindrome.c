#include <stdio.h>

int main(void) 
{
    int n = 10;
    for (int i = 1; i <= n; i++) {
        int revNum = 0;
        int temp = i;

        // собираем десятичное число из перевернутого двоичного
        while (temp > 0) {
        revNum = revNum * 2 + temp % 2;
        temp /= 2;
        }

        if (i == revNum)
        printf("%d\n", i);
    }
    return 0;
}