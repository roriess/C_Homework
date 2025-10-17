#include <stdio.h>
#include <string.h>


int maxSum(int numArr[])
{
    int maxSumma = 0;
    int curSum = 0;

    for (int i = 0; i < strlen(numArr); i++) {
        if (numArr[i] != ' ') {
            curSum = curSum + numArr[i];
        } else {
            if (curSum > maxSumma)
                maxSumma = curSum;

            curSum = 0;
        }
    }

    return maxSumma;
}


int main(void)
{
    int numArr[5] = {1, 45, 9, 10, 2};

    int maxSumma = maxSum(numArr);

    printf("%d\n", maxSumma);

    return 0;
}
