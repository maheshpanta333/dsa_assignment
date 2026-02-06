#include "stack.h"
#include <stdio.h>

char pop(Stack*s){
    char ch;
    if (!isempty(s)){
     ch=s->key[s->top];
    s->top-=1;
    return ch;
    }
    else{
        return '0';
    }
    
}

void push(Stack* s,char c){
    if(!isfull(s)){
    s->top+=1;
    s->key[s->top]=c;}

}
bool isempty(Stack* s){
    if(s->top==-1) return true;
    return false;
}
void initialise(Stack* s){
    s->top=-1;
}

bool isfull(Stack* s){
    if(s->top==MAX_SIZE-1) return true;
    return false;
}

void remove_pos(Stack*s, int x){
    int i=s->top;
    if (isempty(s)) return;
    for (int i;i>x;i++){
       s->key[i]=s->key[i+1];

    }
   s->top-=1;
}