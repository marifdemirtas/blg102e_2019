/* Babylonian method
   Takes an int (N), calculates its square root using a guess method
   Every iteration, a new G(guess) is calculated by taking the median of
   current G and N divided by G, until G squared is close to N
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define EPSILON 1E-5

int main() {
    int n;
    double g;
    srand(time(NULL));
    g = rand();
    printf("Enter the number you want to calculate the square root of: ");
    scanf("%d", &n);
    if (n < 0) {
        printf("A squared number cannot be negative!!!");
        return EXIT_FAILURE;
    }
    do {
    g = (g + n/g) / 2.0;
    } while (fabs(g*g - n) > EPSILON);
    
    printf("Square root of %d is %.2lf\n", n, g);
    return EXIT_SUCCESS;
 
}
