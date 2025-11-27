#include <stdbool.h>
#include <stdio.h>

#include "operationsForCalculations.h"

bool zeroPlusZero()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(0));
    strcpy(binB, intToBin(0));
    int summa = 0;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool zeroPlusElm()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(0));
    strcpy(binB, intToBin(19));
    int summa = 19;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool elmPlusZero()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(19));
    strcpy(binB, intToBin(0));
    int summa = 19;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool elmPlusElm()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(19));
    strcpy(binB, intToBin(91));
    int summa = 110;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool negElmPlusNegElm()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(-19));
    strcpy(binB, intToBin(-91));
    int summa = -110;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool negElmPlusElm()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(-19));
    strcpy(binB, intToBin(34));
    int summa = 15;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool elmPlusNegElm()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(19));
    strcpy(binB, intToBin(-34));
    int summa = -15;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

bool largeElmPlusLargeElm()
{
    char binA[40];
    char binB[40];

    strcpy(binA, intToBin(123456789));
    strcpy(binB, intToBin(123456789));
    int summa = 123456789 * 2;
    int binSum = binToInt(sum(binA, binB));
    return summa == binSum;
}

void runTests()
{
    bool negElmNegElm = negElmPlusNegElm();
    bool negElmElm = negElmPlusElm();
    int result = 1;

    if (!zeroPlusZero()) {
        printf("Error when 0 + 0\n");
        result = 0;
    }
    if (!zeroPlusElm()) {
        printf("Error when 0 + elm\n");
        result = 0;
    }
    if (!elmPlusZero()) {
        printf("Error when elm + 0\n");
        result = 0;
    }
    if (!negElmPlusNegElm()) {
        printf("Error when -elm + -elm\n");
        result = 0;
    }
    if (!negElmPlusElm()) {
        printf("Error when -elm + elm\n");
        result = 0;
    }
    if (!elmPlusNegElm()) {
        printf("Error when elm + -elm\n");
        result = 0;
    }
    if (!largeElmPlusLargeElm()) {
        printf("Error when largeElm + largeElm\n");
        result = 0;
    }
    if (result) {
        printf("Correct!");
    }
    return;
}