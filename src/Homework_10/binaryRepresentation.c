#include <stdio.h>
#include <string.h>

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

    binElm[index] = '\0';

    return binElm;
}

char* sum(char elm1[], char elm2[])
{
    static char elmSum[40];
    int index = 0;
    int rem = 0;
    int len = strlen(elm1) - 1;

    while (len >= 0 || rem) {
        if (elm1[len] == ' ') {
            elmSum[index++] = ' ';
            len--;
            continue;
        }
        int total = (elm1[len] - '0') + (elm2[len] - '0') + rem;
        rem = total / 2;
        elmSum[index++] = (total % 2) + '0';

        len--;
    }

    for (int i = 0; i < index / 2; i++) {
        int temp = elmSum[i];
        elmSum[i] = elmSum[index - 1 - i];
        elmSum[index - 1 - i] = temp;
    }

    elmSum[index] = '\0';

    return elmSum;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);

    char binA[40];
    char binB[40];

    strcpy(binA, bin(a));
    strcpy(binB, bin(b));

    printf("%d: %s\n", a, binA);
    printf("%d: %s\n", b, binB);

    printf("%d + %d: %s\n", a, b, sum(binA, binB));

    return 0;
}