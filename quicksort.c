#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include "cstio.h"

void quicksort(int array[],int size,int low,int high);



int main(int argc, char  **argv){
    // create file pointer    
    FILE *fptr;
    // open file in read mode and assign the pointer to the starting element
    char *arg1 = argv[1];
    fptr = fopen(arg1,"r");
    // get file size  
    struct stat st;
    stat(arg1,&st);
    int  size = st.st_size;
    //get required memory to store integer;
    int intSize = (size+1)*2;
    // allocate memory to the array to be stored
    int array[intSize];
    int n = 0;
    char stringInt[10];
    char temp;
    int j = 0;
    //store the values from the file into variable:array
    for(int i = 0;i<size;i++){
        fscanf(fptr,"%c",&temp);
        if(temp!=' '){
            stringInt[j] = temp;
            j++;
        }
        else{
            array[n] = atoi(stringInt);
            for(int k=0;k<=j;k++){
                stringInt[k] = 0;
            }
            j = 0;
            n++;
        }
        if(i == size-1){
            array[n] = atoi(stringInt);
            for(int k=0;k<=j;k++){
                stringInt[k] = 0;
            }
            j = 0;
            n++;
        }
    }
    
    fclose(fptr);
    
    printArrayInt(array,n);
    quicksort(array,n,0,n-1);    
    printArrayInt(array,n); 
    char *arg2 = argv[2];  
    fptr = fopen(arg2,"wb");
    fwrite(array,4,n,fptr);
    fclose(fptr);
}


void quicksort(int array[],int size,int low ,int high){
    if(low<high){
        int pivot = array[high]; 
        for(int i=low;i<high;i++){
            if (array[i]>pivot){
                for(int j=i+1;j<high;j++){
                    if (array[j]<pivot){
                        int temp = array[j];
                        array[j] = array[i];
                        array[i] = temp;
                    }
                }
            }
        }
        for(int k = low;k<=high;k++){
            if (array[k]>pivot){
                int pivot_pos = k;            
                array[high] = array[k];
                array[k] = pivot;
                quicksort(array,size,low,pivot_pos-1);
                quicksort(array,size,pivot_pos+1,high);
                break;          
                
            }
            else if (k==high)
            {
                quicksort(array,size,low,high-1);
            }
            
        }
        
    }

}





