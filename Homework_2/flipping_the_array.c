#include <stdio.h>
void reverse(int arr[], int left, int right) {
    
}
int main() 
{
    int m, n;
    printf("Enter the length of the first segment 'm' and the length of the second segment 'n' separated by a space: ");
    scanf("%d %d", &m, &n);

    int arrayOfNumbers[m + n];

    for (int i = m + n; i > 0; i--) {
        arrayOfNumbers[i - 1] = i;
    }

    for (int j = 0; j <= m; j++) {
        arrayOfNumbers[j]
    }
}
