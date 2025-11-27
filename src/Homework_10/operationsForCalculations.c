#include <math.h>
#include <string.h>

#include "operationsForCalculations.h"

char* intToBin(int elm)
{
    size_t bits = sizeof(int) * 8;
    static char binElm[40];
    int index = 0;
    int flag = 0;
    if (elm < 0) {
        elm = -elm;
        flag = 1;
    }

    for (int i = bits - 1; i >= 0; i--) {
        binElm[index++] = ((elm >> i) & 1) + '0';

        if (i % 4 == 0 && i != 0)
            binElm[index++] = ' ';
    }
    if (flag) {
        binElm[0] = '1';
    }

    binElm[index] = '\0';

    return binElm;
}

int binToInt(char elm[])
{
    int intElm = 0;
    int len = strlen(elm) - 1;
    int degree = 0;
    int flag = 0;

    if (elm[0] == '1') {
        elm[0] = '0';
        flag = 1;
    }

    while (len >= 0) {
        if (elm[len] != ' ') {
            intElm += (elm[len] - '0') * pow(2, degree);
            degree++;
        }
        len--;
    }

    if (flag)
        intElm = -intElm;

    return intElm;
}

char* sum(char elm1[], char elm2[])
{
    static char elmSum[40];
    int index = 0;
    int len = strlen(elm1) - 1;

    if (elm1[0] == '1' && elm2[0] == '0' || elm2[0] == '1' && elm1[0] == '0') {
        while (len >= 0) {
            if (elm1[len] == ' ') {
                elmSum[index++] = ' ';
                len--;
                continue;
            }
            int total = (elm1[len] - '0') - (elm2[len] - '0');
            elmSum[index++] = total + '0';

            len--;
        }
    } else {
        if (elm1[0] == '1' && elm2[0] == '1')
            elm2[0] = '0';

        int rem = 0;

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
    }

    for (int i = 0; i < index / 2; i++) {
        int temp = elmSum[i];
        elmSum[i] = elmSum[index - 1 - i];
        elmSum[index - 1 - i] = temp;
    }

    elmSum[index] = '\0';

    return elmSum;
}