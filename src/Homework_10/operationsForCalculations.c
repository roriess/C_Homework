#include "operationsForCalculations.h"

char* intToBin(int elm)
{
    size_t bits = sizeof(int) * 8;
    static char binElm[40];
    int index = 0;
    int flag = 0;
    if (elm < 0) {
        elm = -elm;
        flag = 1;
    }

    for (int i = bits - 1; i >= 0; i--)
        binElm[index++] = ((elm >> i) & 1) + '0';

    if (flag)
        binElm[0] = '1';

    binElm[index] = '\0';

    return binElm;
}

int binToInt(char elm[])
{
    int intElm = 0;
    int len = strlen(elm) - 1;
    int degree = 0;
    int flag = 0;

    if (elm[0] == '1') {
        elm[0] = '0';
        flag = 1;
    }

    while (len >= 0) {
        intElm += (elm[len] - '0') * pow(2, degree);
        degree++;
        len--;
    }

    if (flag)
        intElm = -intElm;

    return intElm;
}

void reverse(char arr[], int len)
{
    for (int i = 0; i < len / 2; i++) {
        char temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }
}

char* sum(char elm1[], char elm2[])
{
    static char elmSum[40];
    int index = 0;
    int len = strlen(elm1) - 1;

    if (elm1[0] == '1' && elm2[0] == '0' || elm2[0] == '1' && elm1[0] == '0') {
        while (len >= 0) {
            int total = (elm1[len] - '0') - (elm2[len] - '0');
            elmSum[index++] = total + '0';
            len--;
        }
    } else {
        if (elm1[0] == '1' && elm2[0] == '1')
            elm2[0] = '0';

        int rem = 0;
        while (len >= 0 || rem) {
            int total = (elm1[len] - '0') + (elm2[len] - '0') + rem;
            rem = total / 2;
            elmSum[index++] = (total % 2) + '0';
            len--;
        }
    }

    reverse(elmSum, index);
    elmSum[index] = '\0';

    return elmSum;
}

void printfWithSpaces(char arr[])
{
    int i = 0;
    int count = -1;
    while (arr[i] != '\0') {
        count++;
        if (count == 4) {
            printf(" ");
            count = 0;
        }
        printf("%c", arr[i]);
        i++;
    }
    printf("\n");
}

void process(char* arr, char data[], size_t arrSize)
{
    int i;
    for (i = 0; i < arrSize && data[i] != '\0'; i++)
        arr[i] = data[i];
    arr[i] = '\0';
}