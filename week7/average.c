#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10
#define MOVING_SIZE 3

double cumulative(double sequence[], int input){
    double sum = 0;
    for (int i = 0; i < input; i++){
        sum += sequence[i];
    }
    return sum / input;
}

double simple_moving(double sequence[], int input){
    if (input < MOVING_SIZE){
        return 0;
    }
    double sum = 0;
    for (int j = 0; j < MOVING_SIZE; j++){
        sum += sequence[input-1];
        input--;
    }
    return sum / MOVING_SIZE;
}

void print_array(double to_print[], int input){
    for (int i = 0; i < input; i++){
        printf("%.3lf ", to_print[i]);
        if (i != input - 1){
            printf("| ");
        }
    }
    printf("\n");
    
}

int main(){
    double sequence[SIZE];
    int input = 0;
    double cumulatives[SIZE];
    double movings[SIZE];
    while (input < SIZE){
        double data;
        printf("Enter your data: ");
        scanf("%lf", &data);
        sequence[input] = data;
        input++;
        cumulatives[input-1] = cumulative(sequence, input);
        movings[input-1] = simple_moving(sequence, input);

    }
    print_array(sequence, SIZE);
    print_array(cumulatives, SIZE);
    print_array(movings, SIZE);
    
    return EXIT_SUCCESS;
}