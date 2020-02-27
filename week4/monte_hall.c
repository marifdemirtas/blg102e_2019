#include <stdio.h>
#include <stdlib.h> //
#include <time.h> //time

int main() {
    int counter = 0;
    srand(time(NULL));
    int change=0;                                               // times when car is behind the non-chosen door
    int remain=0;                                               // times when car is behind the first choice
    while (counter<10000){
        counter++;
        int car = rand() % 3 + 1;
        int choice = rand() % 3 + 1;
        int spare;
        if (car != choice){                                     // evaluating starts to find the empty door 
            spare = 6 - (car + choice);
        } else if (car == 3) {
            spare = rand() % 2 + 1;
        } else if (car == 1) {
            spare = rand() % 2 + 2;
        } else {
            spare = rand() % 2 + 1;
            if (spare == 2) {
                spare = 3;
            }
        }                                                     //host opened door number spare and it is empty.
        int second_choice = rand() % 2;
        if (second_choice == 0 && car == choice) {
            remain++;
        } else if (second_choice == 0 && car != choice) {
            change++;
        } else if (second_choice == 1 && car == choice) {
            remain++;
        } else if (second_choice == 1 && car != choice) {
            change++;
        }
    }
    double ratioremain = remain / 100.0;
    double ratiochange = change / 100.0;    
    printf("The contestant tried 10000 times, %.2lf percent of wins were obtained by changing,\n"
            "%.2lf percent of wins were obtained by not changing the original choice.\n", ratiochange, ratioremain);
    return EXIT_SUCCESS;
}
