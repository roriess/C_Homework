#include "operationsForDoubleNum.h"

bool negNum()
{
    union Number num;
    num.value = -12.34;

    char s = findNumSign(num);

    return s == '-';
}

bool posNum()
{
    union Number num;
    num.value = 12.34;

    char s = findNumSign(num);

    return s == '+';
}

bool randomNum()
{
    union Number num;
    num.value = -2.5;

    char s = findNumSign(num);
    double m = findMantissa(num);
    int p = findExponentOfNum(num);

    return s == '-' && (int)(m * 100) / 100.0 == 1.25 && p == 1;
}

void runTests()
{
    int flag = 1;
    if (!negNum()) {
        printf("Error with negative number\n");
        flag = 0;
    }
    if (!posNum()) {
        printf("Error with positive number\n");
        flag = 0;
    }
    if (!randomNum()) {
        printf("Error with random number\n");
        flag = 0;
    }
    if (flag)
        printf("Correct!\n");
    return;
}