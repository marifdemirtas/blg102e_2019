/*
    Chess board coordinates
    Takes a row and a column and
    prints the color of the square
    these coordinates belong to

*/

#include <stdio.h> //printf, scanf
#include <stdlib.h> //EXIT_SUCCESS

int main()
{

    int row;
    int column;
    printf("Please enter the row of the square as a digit: ");
    scanf("%d", &row);
    printf("\nPlease enter the column of the square as a digit: ");
    scanf("%d", &column);

    if ((row + column) % 2 == 0) {
        printf("\nColor[%d,%d] = Black\n", row, column); //black
    } else {
        printf("\nColor[%d,%d] = White\n", row, column); //white
    }
    return EXIT_SUCCESS;
}