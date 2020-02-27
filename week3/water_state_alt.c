/*  Takes inputs temp_value and temp_type, 
    computes the state of water at sea level,
    prints out the state
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE

int main()
{
    int temp_value;
    char temp_type;
    int freeze;
    int boil;
    printf("Please enter the system you're using (C for Celsius, F for Fahrenheit): ");
    scanf("%c", &temp_type);
    printf("Please enter the temperature: ");
    scanf("%d", &temp_value);
    if (temp_type == 'C') {
        freeze = 100;
        boil = 0;
    } else if (temp_type == 'F'){
        freeze = 212;
        boil = 32;
    } else {
        printf("Couldn't determine temperature type. Exiting...\n");
        return EXIT_FAILURE;
    }

    if (temp_value >= freeze) {
        printf("Water is solid\n");
    } else if (temp_value >= boil) {
        printf("Water is liquid\n");
    } else {
        printf("Water is gaseous\n");
    }

    return EXIT_SUCCESS;
}