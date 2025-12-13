#include "operationsForSumDigits.c"

bool sameSum()
{
    int a = 1;
    int b = 2;

    return sumBin(a) == sumBin(b);
}

bool zero()
{
    int a = 0;
    int b = 0;

    return sumBin(a) == sumBin(b);
}

bool bigNum()
{
    int a = 100000000;
    int b = 100000001;

    return sumBin(a) < sumBin(b);
}

bool difNum1()
{
    int a = 54;
    int b = 145;

    return sumBin(a) > sumBin(b);
}

bool difNum2()
{
    int a = 1;
    int b = 34;

    return sumBin(a) < sumBin(b);
}

void runTests()
{
    bool res1 = sameSum() && zero();
    bool res2 = bigNum() && difNum1();
    bool res3 = difNum2() && res1;
    bool finalResul = res3 && res2;

    if (finalResul) {
        printf("Correct!\n");
    } else {
        if (!sameSum())
            printf("Error with the same sum\n");
        if (!zero())
            printf("Error with zero elements\n");
        if (!bigNum())
            printf("Error with a big numbers\n");
        if (!difNum1())
            printf("Error with ordinary elements\n");
        if (!difNum2())
            printf("Error with a ordinary elements\n");
    }
}