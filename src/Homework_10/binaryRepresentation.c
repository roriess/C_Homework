#include <stdio.h>

char* bin(int elm)
{
    size_t bits = sizeof(int) * 8;
    static char binElm[40];
    int index = 0;

    for (int i = bits - 1; i >= 0; i--) {
        binElm[index++] = ((elm >> i) & 1) + '0';

        if (i % 4 == 0 && i != 0)
            binElm[index++] = ' ';
    }

    return binElm;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    printf("%d: %s\n", a, bin(a));
    printf("%d: %s\n", b, bin(b));
    
    return 0;
}