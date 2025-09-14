#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int a, b;

    printf("Enter the digits 'a' and 'b' separated by a space: ");
    scanf("%d %d", &a, &b);

    if (!b) {
        puts("Error. You can't divide by zero (b = 0).");
        return 1;
    }

    int sign = (a * b) < 0 ? -1 : 1;

    a = abs(a);
    b = abs(b);

    int incompleteQuotient = 0;
    while (a >= b) {
        a -= b;
        incompleteQuotient++;
    }

    printf("The incomplete quotient is %d\n", incompleteQuotient * sign);
    return 0;
}