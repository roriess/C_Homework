#include "operationsForSumDigits.h"
#include "tests_sumOfDigits.c"

int main(int argc, char* argv[])
{
    bool flag = 1;
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
        int a = 1;
        int b = 2;

        int sumA = sumBin(a);
        int sumB = sumBin(b);
        if (sumA == sumB) {
            printf("The sum of digits in binary notation is the same.\n");
        } else {
            if (sumA > sumB)
                printf("%d\n", a);
            if (sumB > sumA)
                printf("%d\n", b);
        }
    }
    return 0;
}