#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* n1, int* n2){
    *n1 = *n1 + *n2;
    *n2 = *n1 - *n2;
    *n1 = *n1 - *n2;
}

void print_array_up_to(int* arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/*
void random_fill_array(int size, int* arr){
    for(int i = 0; i < size; i++){
        *arr = rand() % size;
        arr++;
    }
}
*/

void read_array_up_to(int* arr, int size){
    for (int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
}
int main(){
    int size;
    int *arr  = (int*) malloc(sizeof(int)*size);
    
    srand(time(NULL));
    
    printf("Array length: ");
    scanf("%d", &size);
    
//   random_fill_array(size, arr);
    printf("Enter your data: ");
    read_array_up_to(arr, size);
//    print_array_up_to(arr, size);
    for(int i = 0; i < size/2; i++){
        swap(&arr[i],&arr[(size-1)-i]);
    }
    print_array_up_to(arr, size);
    
    return EXIT_SUCCESS;
}