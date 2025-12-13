#include "operationsForSumDigits.h"

int sumBin(int a)
{
    int sum = 0;
    while (a > 0) {
        sum += a % 2;
        a /= 2;
    }
    return sum;
}
