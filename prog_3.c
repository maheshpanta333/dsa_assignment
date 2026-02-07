#include <stdio.h>
#include <stdlib.h>


//struct represneting nodes for doubly link list
typedef struct Node{
    int key;
    struct Node* prev;//points to prev value 
    struct Node* next;//points to next value
}Node;


typedef struct List{
    Node* head;
    Node *tail;
}List;

Node* createnode(int x){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->key=x;
    newnode->prev=NULL;
    newnode->next=NULL;
    return newnode;
}
void insertatend(List* list,int x ){
    if(list->head==NULL){ 
        list->head=createnode(x);
        list->tail=createnode(x);
        return;
    }
    Node* newnode=createnode(x);
    Node* temp=list->tail;
    newnode->prev=temp;
    temp->next=newnode;
    list->tail=newnode;
    return;

}

//this is to free the memory
void deleteall(List* list){
    Node* temp=list->head;
    Node* next_node=(Node*)malloc(sizeof(Node));
    while (next_node!=NULL){
        next_node=temp->next;
        free(temp);
    }
    free(next_node);
    free(temp);
}

//this would do the reverse traversal
void reversal_traversal(List* list){
    Node* temp=list->tail;
    printf("Reverse traversal would be like:\n");
      while (temp!=NULL){
        printf("%d, ",temp->key);
        temp=temp->prev;  
    }

}

int main(){
    List* list=(List*)calloc(1,sizeof(List));//using calloc here to set the values of pointers null
    insertatend(list,5);
    insertatend(list,6);
    insertatend(list,7);
    insertatend(list,8);
    insertatend(list,9);
    reversal_traversal(list);
    deleteall(list);
    free(list);
}