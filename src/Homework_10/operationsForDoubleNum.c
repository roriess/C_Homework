#include "operationsForDoubleNum.h"

char findNumSign(union Number num)
{
    return (num.bits >> 63) ? '-' : '+';
}

double findMantissa(union Number num)
{
    uint64_t m_bits = num.bits & (1ULL << 52) - 1;
    double m = 1.0 + (double)m_bits / TWO_TO_52_POWER;
    return m;
}

int findExponentOfNum(union Number num)
{
    return ((num.bits >> 52) & 0x7FF) - 1023;
}