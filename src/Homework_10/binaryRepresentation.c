#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "operationsForCalculations.c"
#include "testsForBinaryRepresentation.c"

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

    if (flag == 1) {
        int a, b;
        scanf("%d %d", &a, &b);

        char binA[40];
        char binB[40];

        if (a >= 0 && b < 0) {
            int temp = a;
            a = b;
            b = temp;
        }

        strcpy(binA, intToBin(a));
        strcpy(binB, intToBin(b));

        printf("%d to bin: %s\n", a, binA);
        printf("%d to bin: %s\n", b, binB);

        char sumElm[40];
        strcpy(sumElm, sum(binA, binB));


        printf("%d + %d: %s\n", a, b, sumElm);

        printf("%s to int: %d\n", sumElm, binToInt(sumElm));
    }
    
    return 0;
}