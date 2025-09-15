#include <stdio.h>

int main() 
{
    int choice;
    printf("Choose type of number:\n1. Integer\n2. Floating-point\n");
    scanf("%d", &choice);
    

    switch(choice) {
    case 1: {
        int x;
        printf("Enter x value: ");
        scanf("%d", &x);

        int polynomialValue = ((x*x + 1)*(x*x) + x) + 1;

        printf("The value of the formula x^4 + x^3 + x^2 + x + 1 when x = %d is equal to %d\n", x, polynomialValue);
        return 0;
    }
    case 2: {
        double x;
        printf("Enter x value: ");
        scanf("%lf", &x);

        double polynomialValue = ((x*x + 1)*(x*x) + x) + 1;

        printf("The value of the formula x^4 + x^3 + x^2 + x + 1 when x = %.2f is equal to %.2f\n", x, polynomialValue);
        return 0;
    }
    default:
        printf("Invalid choice.\n");
        return 1;
    }
}
