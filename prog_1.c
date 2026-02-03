#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 20
char opening[3]={'(','{','['};
char closing[3]={')','}',']'};
//this would be the stack
typedef struct stack{
    char key[MAX_SIZE];
    int top;
} Stack;

//to check if its empty
bool isempty(Stack* s){
    if(s->top==-1) return true;
    return false;
}


//to push
void push(Stack* s,char c){
    s->top+=1;
    s->key[s->top]=c;

}

//to pop the values
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

//to check if it is opening or closing bracket
int isbracket(char c){
    int i=0;
    for(i=0;i<3;i++){
        if(opening[i]==c) return 1;
        else if(closing[i]==c) return 2;
        return 3;
    }
}
//function that would check for the balanced parantheses
bool is_balanced(char* str){
int i=0;
int size_=size(str);
int isbracket_;
Stack* s;
s->top=-1;
for(i=0;i<size_;i++){
    isbracket_=isbracket(str[i]);
    if(isbracket_!=3){//here 3 means there should be no brackets
    if(isempty(s)){
        push(s,str[i]);
        continue;//then we just look for next string 
    }
    

}
}

}