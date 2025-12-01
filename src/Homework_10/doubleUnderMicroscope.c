#include <stdint.h>
#include <stdio.h>


#define TWO_TO_52_POWER 4503599527370496.0

int main(void)
{
    double valueNum;
    printf("Enter a number: ");
    scanf("%lf", &valueNum);

    union Number {
        double value;
        uint64_t bits;
    };

    union Number num;
    num.value = valueNum;

    char s = (num.bits >> 63) ? '-' : '+';

    uint64_t m_bits = num.bits & (1ULL << 52) - 1;
    double m = 1.0 + (double)m_bits / TWO_TO_52_POWER;

    int p = ((num.bits >> 52) & 0x7FF) - 1023;

    printf("Result: %c%g*2^%d\n", s, m, p);

    return 0;
}