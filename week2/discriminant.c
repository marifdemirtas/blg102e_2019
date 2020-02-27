#include <stdio.h> // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS
#include <math.h> // sqrt, pow

int main()
{
    int a, b, c;
    double x1, x2;

    printf("For your polynomial which is in the form\n ax^2 + bx + c\nplease enter the coefficients a, b and c.\n");
    scanf("%d %d %d", &a, &b, &c);

    int discriminant = pow(b, 2) - 4 * a * c;

    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);

    printf("Two roots of the polynomial are x1 = %.2lf and x2 = %.2lf\n", x1, x2);

    return EXIT_SUCCESS;
}