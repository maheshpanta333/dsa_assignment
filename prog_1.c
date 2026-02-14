#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
#include <stdlib.h>
char opening[3] = {'(', '{', '['};
char closing[3] = {')', '}', ']'};
/*
i am using stach.h file that i made because i need to use stack for two questions
*/
//to check if the opening and closing brackets match
bool ismatch(char c1,char c2){//c1 has to be openinig bracket and the closing bracket alwasy has to be c2
    int i=0;
    for (i=0;i<3;i++){
        if(c1==opening[i] && c2==closing[i]) return true;

    }
    return false;
}

//to check if it is opening or closing bracket
int isbracket(char c){
    int i=0;
    for(i=0;i<3;i++){
        if(opening[i]==c) return 1;
        else if(closing[i]==c) return 1;
        
    }
    return 0;
}
//function that would check for the balanced parantheses
bool is_balanced(char* str){
int i=0;
int size_=strlen(str);
int isbracket_;
Stack* s=(Stack*)malloc(sizeof(Stack));
initialise(s);
for(i=0;i<size_;i++){
    isbracket_=isbracket(str[i]);
    if(isempty(s) && isbracket_){
        push(s,str[i]);
        continue;//then we just look for next string 
    }
    if(!isbracket_){
        continue;
    }
    if(ismatch(s->key[s->top],str[i])){
        pop(s);
        continue;
    }
    push(s,str[i]);



    

}
if(isempty(s)){ 
    free(s);
    return true;} //return true if the stack is empty
    free(s);
return false;//return false if the stack is not empty
}

void check_balance(char* ch){
    bool x;
    x=is_balanced(ch);
    if(x){
        printf("Given expression has balanced parantheses!\n");
        return;
    }
    printf("Given expression has unbalanced parantheses!\n");

}

int main(){
    char exp1[]="a + (b − c) ∗ (d)";
    char exp2[]="m + [a − b ∗ (c + d ∗ {m)]";
    char exp3[]="a+(b-c)";
    check_balance(exp1);
    check_balance(exp2);
    check_balance(exp3);
    return 0;
}


