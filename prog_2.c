#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include <string.h>


bool get_associativity(int a,int b){
if(a==1 && b==1) return false
//we return false for right to left associativity in expoential operator else we return true
return true;
}



int get_priority(char a){// for the brackets what i have done is taken number from 4 to 6 for 3 brackets and assigned square of those number for the closing bracket
    switch (a)
    {
    case '(':
    return 4;
    break;
    case ')':
    return 16;
    break;
    case '{':
    return 5;
    break;
      case '}':
    return 25;
    break;
    case '[':
    return 6;
    break;
      case ']':
    return 36;
    break;
    case '^':
    return 1;
    break;
    case '/':
        return 2;
        break;
     case '*':
        return 2;
        break;
    case '%':
        return 2;
        break;
     case '+':
        return 3;
        break;
     case '-':
        return 3;
        break;
    
    default:
        break;
    }
}
int check_priority(char a,char b){//sending int values to recognise the brackets
    //here char a should be the top of the stack and then char b be the value from the expression to check the precedence
    
    
}


char* convert_to_postfix(char* exp){

}

int main(){

}