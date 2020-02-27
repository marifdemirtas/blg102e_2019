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

    if (row % 2 == 0) {
        if (column % 2 == 0) {
            printf("\nColor[%d,%d] = Black", row, column); //black
        } else {
            printf("\nColor[%d,%d] = White", row, column); //white
        }
    } else {
        if (column % 2 == 0) {
            printf("\nColor[%d,%d] = White", row, column); //black
        } else {
            printf("\nColor[%d,%d] = Black", row, column); //white
        }
    }
    return EXIT_SUCCESS;
}