#include <stdio.h>
#include<stdlib.h>

//represents the linked list
typedef struct Node{
    int key;
    struct Node* prev;//points to prev value 
    struct Node* next;//points to next value
}Node;


//representing the nodes as list
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
    Node* newnode = createnode(x);
    list->head = newnode;
    list->tail = newnode;
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
    Node* current=list->head;
    while (current!=NULL){
        Node* next_node = current->next; // Save the next address first
        free(current);                   // Then free current
        current = next_node;
    }
    free(list);
}


void reversal_traversal(List* list){
    Node* temp=list->tail;
    printf("Reverse traversal would be like:\n");
      while (temp!=NULL){
        printf("%d, ",temp->key);
        temp=temp->prev;  
    }
    printf("\n");

}


//this function would insert certain value at the given position
void insert_valueat(List* list, int x, int pos){
  if(list->head==NULL|| pos <= 0){ 
    Node* newnode = createnode(x);
    list->head = newnode;
    list->tail = newnode;
        return;
    }
    Node* temp=list->head;
    int i=0;
    for(i=0;i<pos-1&& temp->next != NULL;i++){
        temp=temp->next;
        
    }

 Node* newnode=createnode(x);
    Node* old_next = temp->next;  
    
    newnode->prev = temp;
    newnode->next = old_next;
    temp->next = newnode;
    
    if (old_next != NULL) {
        old_next->prev = newnode;
    } else {
        list->tail = newnode;
    }
    
    return;
}



int main(){
    List* list=(List*)calloc(1,sizeof(List));//using calloc here to set the values of pointers null
    insertatend(list,5);
    insertatend(list,6);
    insertatend(list,7);
    insertatend(list,8);
    insertatend(list,9);
    reversal_traversal(list);
    insert_valueat(list,10,3);
    reversal_traversal(list);
    deleteall(list);
}