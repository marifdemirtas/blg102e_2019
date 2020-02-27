#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double getRandomNumber(double lower_limit, double upper_limit){
	double num = rand();
	double fraction = (upper_limit-lower_limit) / RAND_MAX;
	num = num * fraction + lower_limit;
	return num;
}

int main(){
	srand(time(NULL));
	printf("%.2lf\n",getRandomNumber(-7,7));
	return 0;
}
