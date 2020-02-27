/*  Takes inputs temp_type, temp_value, altitude
    calculates the value in Celsius,
    computes the boiling point of water at given altitude,
    prints out the state
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
    double temp_value;
    char temp_type;
    int altitude;
    printf("Please enter the system you're using (C for Celsius, F for Fahrenheit): ");
    scanf("%c", &temp_type);
    printf("Please enter the temperature: ");
    scanf("%lf", &temp_value);
    printf("Please enter the altitude in meters: ");
    scanf("%d", &altitude);

    if (temp_type == 'F') {
        const double celsius_const = 5.0 / 9.0; // 5/9
        const int celsius_dif = 32;
        temp_value = (temp_value - celsius_dif) * celsius_const;
    }

    int boil = 100 - (altitude / 300);
    int freeze = 0;

    if (temp_value <= freeze) {
        printf("Water is solid\n");
    } else if (temp_value <= boil) {
        printf("Water is liquid\n");
    } else {
        printf("Water is gaseous\n");
    }

    return EXIT_SUCCESS;
}