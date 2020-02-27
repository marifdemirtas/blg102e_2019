#include <stdio.h>
#define SIZE 6

void print_array_up_to(int array[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", array[i]);
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
            if (array[i] > array [i+1]){
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
    printf("Type 1 for ascending, 2 for descending: ");
    scanf("%d", &type);
    
    bubble_sort(array, type, SIZE);
    
    print_array_up_to(array, SIZE);
    return 0;
}