#include "operationsForDoubleNum.h"
#include "testsForDoubleUnderMicroscope.c"

#define TWO_TO_52_POWER 4503599527370496.0

int main(int argc, char* argv[])
{
    int flag = 1;
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "--test") == 0) {
                runTests();
                flag = 0;
                break;
            }
        }
    }
    if (flag) {
        double valueNum;
        printf("Enter a number: ");
        scanf("%lf", &valueNum);

        if (valueNum == 0.0) {
            printf("Result: +0.0*2^0\n");
        } else {
            union Number num;
            num.value = valueNum;
            char s = findNumSign(num);
            double m = findMantissa(num);
            int p = findExponentOfNum(num);

            printf("Result: %c%g*2^%d\n", s, m, p);
        }
    }

    return 0;
}