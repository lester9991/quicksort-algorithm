#include <stdio.h>

void printArrayInt(int array[],int size);

void printArrayInt(int array[],int size){
    printf("[");
    for(int i = 0;i<size;i++){
        printf(" %d ",array[i]);
    };
    printf("]\n");
}
