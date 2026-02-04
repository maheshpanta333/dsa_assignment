#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stack.h>
char opening[3] = {'(', '{', '['};
char closing[3] = {')', '}', ']'};

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
initialise(s);
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

