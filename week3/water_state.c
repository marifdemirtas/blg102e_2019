/*  Takes inputs temp_value and temp_type, 
    computes the state of water at sea level,
    prints out the state
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS

int main()
{
    int temp_value;
    char temp_type;
    printf("Please enter the system you're using (C for Celsius, F for Fahrenheit): ");
    scanf("%c", &temp_type);
    printf("Please enter the temperature: ");
    scanf("%d", &temp_value);

    if (temp_type == 'C') {
        if (temp_value >= 100) {
            printf("Water is solid\n");
        } else if (temp_value >= 0) {
            printf("Water is liquid\n");
        } else {
            printf("Water is gaseous\n");
        }
    } else if (temp_type == 'F') {
        if (temp_value >= 212) {
            printf("Water is solid\n");
        } else if (temp_value >= 32) {
            printf("Water is liquid\n");
        } else {
            printf("Water is gaseous\n");
        }
    } else {
        printf("Couldn't determine temperature type. Exiting...\n");
    }
    
    return EXIT_SUCCESS;
}