#include <stdio.h>
#include <stdlib.h>

int synthetic_division(int degree, float coefficients[], float divisor, float *quotient, float *remainder)
{
    *remainder = coefficients[0];
    for (int i = 0; i < degree; i++)
    {
        quotient[i] = *remainder / divisor;
        *remainder = coefficients[i + 1] + *remainder * -divisor;
    }
    return (*remainder == 0);
}

void find_factors(int degree, float coefficients[])
{
    float *quotient = malloc(degree * sizeof(float));
    float remainder;
    for (int divisor = -10; divisor <= 10; divisor++)
    {
        if (synthetic_division(degree, coefficients, divisor, quotient, &remainder))
        {
            printf("%d, ", divisor);
        }
    }
    free(quotient);
}

int main()
{
    int degree;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);
    float coefficients[degree + 1];
    printf("Enter the coefficient values (highest degree first): ");
    for (int i = 0; i <= degree; i++)
        scanf("%f", &coefficients[i]);

    printf("Factors: ");
    find_factors(degree, coefficients);
    printf("\n");

    return 0;
}
