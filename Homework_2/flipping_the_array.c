#include <stdio.h>

void reverse(int arr[], int leftEdge, int rightEdge) {
    while (leftEdge < rightEdge) {
        int temporaryVariable = arr[leftEdge];
        arr[leftEdge] = arr[rightEdge];
        arr[rightEdge] = temporaryVariable;

        leftEdge++;
        rightEdge--;
    }
}


int main() 
{
    int m, n;

    printf("Enter the digits 'm' and 'n' separated by a space: ");
    scanf("%d %d", &m, &n);

    int sizeArr = m + n;
    int arr[sizeArr];
    for (int i = 0; i < sizeArr; i++)
        arr[i] = i + 1;
 
        
    printf("The original array: ");
    for (int j = 0; j < sizeArr; j++) {
        printf("%d ", arr[j]);
    }
    printf("\n");


    reverse(arr, 0, m - 1); // flip the first part of the array
    reverse(arr, m, m + n - 1); // flip the second part of the array
    reverse(arr, 0, m + n - 1); // flip the entire array


    printf("The modified array: ");
    for (int k = 0; k < sizeArr; k++)
        printf("%d ", arr[k]);

    return 0;
}
