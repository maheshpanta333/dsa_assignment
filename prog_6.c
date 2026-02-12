#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//we can swap values by creating pointers
void swap(int* a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void minheapify(int *arr, int max, int pos){

    int smallest=pos;
    int left, right;
    left=2*pos+1;
    right=2*pos+2;

   
    if(left < max && arr[left] < arr[smallest]){//checking if the left child has bigger value
        smallest=left;
    }
    if(right < max && arr[smallest]>arr[right]){//checking the right child has bigger value
        smallest=right;
    }

    //now check if the node seems to have balanced value that is largest value has not changed
    if(smallest!=pos){
        //if the parent node is not the smallest value swap them with the child and again check for the node
        swap(&arr[pos],&arr[smallest]);
        //since now the parent node goes down we check for other children node if they are different
        minheapify(arr,max,smallest);
        //here smallest is the index of child node that got replaced with the parent node
        //so now check for its kids as well if we gotta change
    }


}
void maxheapify(int *arr, int max, int pos){

    int largest=pos;
    int left, right;
    left=2*pos+1;
    right=2*pos+2;


    if(left < max && arr[largest]<arr[left]){//checking if the left child has bigger value
        largest=left;
    }
    if(right<max &&arr[largest]<arr[right]){//checking the right child has bigger value
        largest=right;
    }

    //now check if the node seems to have balanced value that is largest value has not changed
    if(largest!=pos){
        //if the parent node is not the largest value swap them with the child and again check for the node
        swap(&arr[pos],&arr[largest]);
        //since now the parent node goes down we check for other children node if they are different
        maxheapify(arr,max,largest);
        //here largest is the index of child node that got replaced with the parent node
        //so now check for its kids as well if we gotta change
    }


}


void build_max(int* arr, int n){
    //n is the index for last element in the leaf node
    int i=(n-1)/2;
    for(i;i>=0;i--){
        maxheapify(arr,n,i);//sends from last node
    }

}

//this will build the min heap
void build_min(int* arr, int n){
    //n is the index for last element in the leaf node
    int i=(n-1)/2;
    for(i;i>=0;i--){
        minheapify(arr,n,i);//sends from last node
    }

}

void input(int *arr,int n){
    int size=n;

    printf("Insert all numbers:\n");
    int i;
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
}


void display(int *arr, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%d, ",arr[i]);
    }
    printf("\n");
}


//now the main function
int main(){

    int size;
    printf("\nHow many numbers in array:\n");
    scanf("%d",&size);
    int* arr=(int*)malloc(sizeof(int)*size); 
    input(arr,size);
    printf("Unsorted array is:\n");
    display(arr,size);
    build_max(arr,size);
    printf("Max heap would be:\n");
    display(arr,size);
    printf("Min heap would be:\n");
    build_min(arr,size);
    display(arr,size);
    free(arr);
    
}