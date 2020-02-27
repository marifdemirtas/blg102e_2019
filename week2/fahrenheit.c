#include <stdio.h> // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS

int main()
{
    double fahrenheit_value = 0.0;

    printf("Enter a temperature value in Fahrenheit:");
    scanf("%lf", &fahrenheit_value);

    const double celsius_const = 5.0 / 9.0; // 5/9
    const int celsius_dif = 32;

    double celsius_value = (fahrenheit_value - celsius_dif) * celsius_const;

    printf("Equivalent Celsius value is %.2lf\n", celsius_value);

    return EXIT_SUCCESS;
}