#include <stdio.h>

#define MAX_SUM 27 // Maximum possible sum of three digits
#define MIN_SUM 0 // Minimum possible sum of three digits

int main()
{
    int sum;
    printf("Enter the sum of three digits(between %d and %d): ", MIN_SUM, MAX_SUM);
    scanf("%d", &sum);

    if (sum < MIN_SUM || sum > MAX_SUM) {
        printf("Incorrect amount. The sum must be between %d and %d.\n", MIN_SUM, MAX_SUM);
        return 1;
    }

    int count = 0;

    for (int ticketNumber = 100000; ticketNumber < 1000000; ticketNumber++) { 
        char strTicketNumber[7];
        sprintf(strTicketNumber, "%d", ticketNumber);

        int digits[6];
        for (int i = 0; i < 6; i++) {
            digits[i] = strTicketNumber[i] - '0';
        }
 
        if ((digits[0] + digits[1] + digits[2]) == sum && (digits[3] + digits[4] + digits[5]) == sum)
            count++; 
    }

    printf("%d\n", count);
    return 0;
}
