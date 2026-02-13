#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void generate_random_array(int* array,int size){
    int i;//this is will just assign random values to the array
    srand(time(NULL));
    for (i=0;i<size;i++){
        array[i]=rand()%1000+1;
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
    int comparisons=0;
    int swapped=0;
    for(;i<n;i++){
        for(j=i;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j+1],&arr[j]);
                swapped++;
            }
            comparisons++;
        }
    }
    printf("Using this algorithm, we compared numbers for %d and swapped them for %d times.\n",comparisons,swapped);
    printf("Array after sorted is:\n");
    display(arr,n);


}


//selection sort would be like as follows
void selectionsort(int * arr, int n){
    int smallest;
    int i,j;
    int swapped=0;
    int comparisons=0;
    //we take small value for all values then jsut compare it with others to swap the places
    // so we gotta take loop from 0 to n-1
    for(i=0;i<n-1;i++){
        smallest=i;
        for(j=i+1;j<n;j++){
            if(arr[smallest]>arr[j]){
                smallest=j;
            }
            comparisons++;
        }
        swap(&arr[i],&arr[smallest]);
        swapped++;
    }
        printf("Using this algorithm, we compared numbers for %d and swapped them for %d times.\n",comparisons,swapped);
        printf("Array after sorted is:\n");
        display(arr,n);
}



void insertion_sort(int *arr,int size){
    int i,j;
    int val;
    int swapped=0;
    int comparisons=0;
    for (i=1;i<size;i++){
        val=arr[i];
        j=i-1;
        //now we go through everything to sort them
        while(j>=0 && arr[j]>val){
            arr[j+1]=arr[j];
            swapped++;
            comparisons++;
            j-=1;
        }
        arr[j+1]=val;
    }
        printf("Using this algorithm, we compared numbers for %d and swapped them for %d times.\n",comparisons,swapped);
        printf("Array after sorted is:\n");
        display(arr,size);

}

//this would merge everything 
void merge(int* arr, int left,int mid,int right,int* comparisons, int* swapped){
    int i,j;
    int n1=mid-left+1;
    int n2=right-mid;
    int* left_val=(int*)malloc(n1*sizeof(int));
    int* right_val=(int*)malloc(n2*sizeof(int));
    for( i=left;i<mid+1;i++){
        left_val[i-left]=arr[i];
    }
     for( i=mid+1;i<=right;i++){
        right_val[i-(mid+1)]=arr[i];
    }
    //these would act as pointers for two matrices it gets
    i=0;//for left subbranch
    j=0;//for right subbranch
    int k=left;//this would let it know where to start
    //now coampare those value and just insert into the main array
    while(i<n1 && j<n2){
        if(left_val[i]<=right_val[j]){
            arr[k]=left_val[i];
            i++;
        }
        else if(left_val[i]>right_val[j]){
            arr[k]=right_val[j];
            j++;//increment value of j

        }
        (*comparisons)++;
        (*swapped)++;
        k++;
    }
    //this is for when left array still has values but right doesnot
    while(i<n1){
        arr[k++]=left_val[i++];
    }
    //this is for when right array still has values but left doesnot
     while(j<n2){
        arr[k++]=right_val[j++];
    }
    free(left_val);
    free(right_val);

}


//this would divide the array into several halves
void mergesort(int* arr,int left, int right,int* comparisons, int* swapped){
    if(left>=right) return;
    int middle=left+((right-left)/2);
    mergesort(arr, left,middle,comparisons,swapped);
    mergesort(arr,middle+1,right,comparisons,swapped);
    merge(arr,left, middle,right,comparisons,swapped);


}


void merge_helper(int* arr, int size){
    int* comparisons=(int*)calloc(1,sizeof(int));
    int* swapped=(int*)calloc(1,sizeof(int));
    mergesort(arr,0,size-1,comparisons,swapped);
    printf("Using this algorithm, we compared numbers for %d and swapped them for %d times.",*comparisons,*swapped);
    printf("Array after sorted is:\n");
    display(arr,size);
    free(comparisons);
    free(swapped);
}


int main(){
    printf("=====Sorting Calculator=====");
    int choice,size=1;
    bool con=true;
    int* array=(int*)malloc(sizeof(int)*size);
    while(con){
    printf("\n Which algorithm do you want to test?\n1) Bubble sort\n2)Insertion\n3)Selection sort\n4)Merge sort\n5)Exit the program!\n");
    scanf("%d",&choice);
    printf("What should be the size of the array?\n");
    scanf("%d",&size);
    array=(int*)realloc(array,size*sizeof(int));
    generate_random_array(array, size);
    printf("Unsorted array is :");
    display(array,size);
    switch(choice){
        case 1:
        bubblesort(array,size);
        break;
        case 2:
        insertion_sort(array,size);
        break;
        case 3:
        selectionsort(array,size);
        break;
        case 4:
        merge_helper(array,size);
        break;
        case 5:
        con=false;
        break;
        default:
        printf("Wrong choice! Try again!\n");
        break;

    }
}
free(array);
}

