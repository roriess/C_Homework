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

        char binA[33];
        char binB[33];

        if (a >= 0 && b < 0) {
            int temp = a;
            a = b;
            b = temp;
        }

        process(binA, intToBin(a), sizeof(binA));
        process(binB, intToBin(b), sizeof(binB));

        printf("%d to bin: ", a);
        printfWithSpaces(binA);
        printf("%d to bin: ", b);
        printfWithSpaces(binB);

        char sumElm[40];
        strcpy(sumElm, sum(binA, binB));

        printf("%d + %d: ", a, b);
        printfWithSpaces(sumElm);

        printf("to int: %d", binToInt(sumElm));
    }

    return 0;
}