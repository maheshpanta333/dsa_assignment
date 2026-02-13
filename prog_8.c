#include <stdio.h>
#include <stdlib.h>


void generate_random_array(int* array,int size){
    int i;//this is will just assign random values to the array
    srand(time(NULL));
    for (i=0;i<size;i++){
        array[i]=rand();
    }


}
//to display the array

void display(int *arr, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d, ",arr[i]);
    }
    printf("\n");
}

//this will just swap the values
void swap(int* a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


//this is for bubble sorting
void bubblesort(int* arr,int n){
    int i=0;
    int j;
    for(;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }

}


//selection sort would be like as follows
void selectionsort(int * arr, int n){
    int smallest;
    int i,j;
    //we take small value for all values then jsut compare it with others to swap the places
    // so we gotta take loop from 0 to n-1
    for(i=0;i<n-1;i++){
        smallest=arr[i];
        for(j=i+1;j<n;j++){
            if(arr[smallest]>arr[j]){
                smallest=j;
            }
        }
        swap(&arr[i],&arr[smallest]);
    }
}

