#include <stack.h>
#include <stdio.h>

char pop(Stack*s){
    char ch;
    if (!isempty(s)){
    char ch=s->key[s->top];
    s->top-=1;
    }
    else{
        return "0";
    }
    return ch;
}

void push(Stack* s,char c){
    s->top+=1;
    s->key[s->top]=c;

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