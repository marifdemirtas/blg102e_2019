/* Body Surface Area (BSA) Calculator
	Uses Boyd Formula, which is as follows:
	BSA (m2) = 0.0003207 x Height^0.3 x Weight^(0.7285 - (0.0188 x log(10)Weight))
	Height is in cm and Weight is in grams
*/

#include <stdio.h> // printf, scanf
#include <stdlib.h> // EXIT_SUCCESS
#include <math.h> // log10, pow

int main()
{
    double weight = 100;
    double height = 100;
    double bsa;

    printf("Your height in centimeters:");
    scanf("%lf", &height);

    printf("Your weight in grams:");
    scanf("%lf", &weight);

    double weight_pow = 0.7285 - (0.0188 * log10(weight));
    bsa = 0.0003207 * pow(height, 0.3) * pow(weight, weight_pow);

    printf("BSA is calculated as %lf\n", bsa);
    return EXIT_SUCCESS;
}
