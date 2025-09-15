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

    int arr[m + n];
    for (int i = 0; i < (m + n); i++) {
        arr[i] = i + 1;
    }

    reverse(arr, 0, m - 1); // flip the first part of the array
    reverse(arr, m, m + n - 1); // flip the second part of the array
    reverse(arr, 0, m + n - 1); // flip the entire array

    for (int j = 0; j < (m + n); j++) {
        printf("%d ", arr[j]);
    }

    return 0;

}
