#include <stdio.h>
#define SIZE 6

double getRandomNumber(double lower_limit, double upper_limit){
	double num = rand();
	double fraction = (upper_limit-lower_limit) / RAND_MAX;
	num = num * fraction + lower_limit;
	return num;
}

void print_array_up_to(int array[], int n){
    for (int i = 0; i < n; i++){
        array[i] = getRandomNumber(0, n);
    }
    printf("\n");
}

void read_array_up_to(int array[], int n){
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }
}

void reverse(int array[], int size){
    int temp[size];
    for (int i = 0; i < size; i++){
        temp[(size-1)-i] = array[i]; 
    }
    for (int i = 0; i < size; i++){
        array[i] = temp[i]; 
    }
}

void bubble_sort(int array[], int type, int size){
    for (int stop = size; stop > 0; stop--){
        for (int i = 0; i < stop - 1; i++){
            if (array[i] < array [i+1]){
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
    if (type == 2){
        reverse(array, size);
    }
}


int main(){
    int array[SIZE];
    printf("Enter %d elements: ",SIZE);
    read_array_up_to(array, SIZE);
    
    int type;
    printf("Type 1 for descending, 2 for ascending: ");
    scanf("%d", &type);
    
    bubble_sort(array, type, SIZE);
    
    print_array_up_to(array, SIZE);
}