#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* n1, int* n2){
    printf("swap başlar");
    *n2 = (*n1) * (*n2);
    *n1 = (*n2) / (*n1);
    *n2 = (*n2) / (*n1);
    
}

void print_array_up_to(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void random_fill_array(int size, int* arr){
    for(int i = 0; i < size; i++){
        *arr = rand() % size*2;
        arr++;
    }
}

int main(){
    int size;
    int *arr  = (int*) malloc(sizeof(int)*size);
    
    srand(time(NULL));
    
    printf("Array length: ");
    scanf("%d", &size);
    
    random_fill_array(size, arr);
    print_array_up_to(arr, size);
    printf("reached 1");
    int *end = arr + size -1;
    printf("reached 2");    
    for(int i = 0; i < size/2.0; i++){
        swap(arr+i,end-i);
    }
    free(arr);
    print_array_up_to(arr, size);
    
    return EXIT_SUCCESS;
}