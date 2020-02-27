/*
	Monte Carlo Method
	Random points in circle / in total = pi over 4
	x^2 + y^2 <= 0 --- condition of being in circle
	unit circle in a 2x2 square
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getRandomNumber(double lower_limit, double upper_limit){
	double num = rand();
	double fraction = (upper_limit-lower_limit) / RAND_MAX;
	num = num * fraction + lower_limit;
	return num;
}

double calculatePi(int max_iteration){
	double area_circle = 0;
	for (int i = 0; i < max_iteration; i++){
		double x_coor = getRandomNumber(-1,1);
		double y_coor = getRandomNumber(-1,1);
		if ((x_coor)*(x_coor) + (y_coor)*(y_coor) < 1){
			area_circle++;
		}
	}
	double pi = (area_circle / max_iteration) * 4;
	return pi;
}

int main(){
	srand(time(NULL));
	int max_i;
	printf("Max iteration: ");
	scanf("%d", &max_i);

	double pi_guess = calculatePi(max_i);
	printf("Pi is calculated as %lf\n", pi_guess);
// above two lines can be run in a for loop and you can get the avg result
	return EXIT_SUCCESS;
}