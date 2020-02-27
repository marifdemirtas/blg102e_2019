/* combination
    C(n,r) = n! / (r! * (n-r)!)
*/
#include <stdio.h>
#include <stdlib.h>

unsigned long int factorial(int upper_limit){
    if (upper_limit<0) {
        printf("Negative number!!");
        return -1;
    }
    unsigned long int product = 1;
    while (upper_limit > 0) {
        product *= upper_limit;
        upper_limit--;
    }
   
    return product;
}

unsigned long int combination(int n, int r) {
    unsigned long int result = ((factorial(n)) / (factorial(r) * factorial(n-r)));
    return result;
}

unsigned long int combination_v2(int n, int r) {
    int temp1, temp2, temp3;
    if (r > (n-r)){
        temp1 = factorial(n-r);
 
    }
    return result;
}

int main(){
    int com_1;
    int com_2;
    printf("Enter n and r for C(n,r): ");
    scanf("%d", &com_1);
    if (com_1 > 20) {
        printf("This program can only handle numbers up to 20. Exiting...\n");
        return EXIT_FAILURE;
    }
    scanf("%d", &com_2);
    if (com_2 > com_1) {
        printf("r cannot be greater than n! Exiting...\n");
        return EXIT_FAILURE;
    }
    
    int c_result = combination(com_1,com_2);

    printf("Combination of %d with %d is %d.\n", com_1, com_2, c_result);
    return EXIT_SUCCESS;
}