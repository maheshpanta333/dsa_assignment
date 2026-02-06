#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include <string.h>
#include <math.h>


bool get_associativity(int a,int b){

if(a==1 && b==1) return false;


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
        return 0;
    }
}
int check_priority(char a,char b){//sending int values to recognise the brackets
    //here char a should be the top of the stack and then char b be the value from the expression to check the precedence
    int x,y; //x is the priority of the char of the top of the stack and y is the priority of the char from the given expression
    x=get_priority(a);
    y=get_priority(b);
    if(y==0) return 0; //return 0 when the given char is operand rather than a operator
    if(x>=4) return 1;
    if(x==y){
        //this condition is for opreators with same precendence
        int b=get_associativity(x,y);
        if(!b) return 1;
        else return 2;
    }
    // i am using 0 if i just need to add to the expression, 1 when i got to push and 2 if i need to pop
 if(x>y) return 1;//this is for when higher priority appears in the expression in comparsion to the top of the stack
return 2;
    
}


void convert_to_postfix(char* exp){
    Stack* s=(Stack*)malloc(sizeof(Stack));
    char temp;
    initialise(s);
    int size=strlen(exp);
    char* final=(char*)malloc(size+1);
    final[0]='\0';
    int a,b,priority_counter,counter=0;
    int i=0;
    for (i;i<size;i++){

        if(isempty(s)){
            a=get_priority(exp[i]);
            if(a!=0){
                push(s,exp[i]);
                
            }
            else if(a==0){
                //when given operand
                final[counter]=exp[i];
                counter++;
                final[counter]='\0';
            }
            continue;
            
        }
        a=get_priority(s->key[s->top]);
        b=get_priority(exp[i]);
        if(b==4||b==5||b==6){
            //this is when opening bracket appears from the wild
            push(s,exp[i]);
            continue;
        }
        if(b==16||b==25||b==36){
            //this is when closing bracket appears from the wild
            while (!isempty(s) && get_priority(s->key[s->top]) != sqrt(b)){
            temp=pop(s);
            final[counter]=temp;
            counter++;
            final[counter]='\0';
            }
            if(!isempty(s)) pop(s);
            continue;
            
        }
        
        priority_counter=check_priority(s->key[s->top],exp[i]);
            // i am using 0 if i just need to add to the expression, 1 when i got to push and 2 if i need to pop
        if(priority_counter==0){
            //for operands
            final[counter]=exp[i];
            counter++;
            final[counter]='\0';
            continue;
        }
        else if(priority_counter==1){
            //when stack's top operator has lower precedence than the exp's operator
            push(s,exp[i]);
            continue;
        }
        else {
            //when we send 2 to pop the value and insert the value
            while(!isempty(s) && check_priority(s->key[s->top],exp[i])==2){
                //run the loop until stack is not empty and all the top has higher precedence
            temp=pop(s);
            final[counter]=temp;
            counter++;
            final[counter]='\0';
            }
            push(s,exp[i]);
            continue;

        }


    }
    //after completing the expression
    while(!isempty(s)){
        temp=pop(s);
        final[counter]=temp;
        counter++;
        final[counter]='\0';

    }
    //this would print the expression
    printf("Postfix expression is:\n");
    for(i=0;i<counter;i++){
        printf("%c",final[i]);
    }

    printf("\n");
    free(final);
    free(s);

}

int main(){
    char a[10]="a+b*c-d";
    char b[10]="a^b+b*c-d";
    char c[10]="a+(b*c)-d";
    char d[15]="a+(b*c+ef-d)-p";
    convert_to_postfix(a);
    convert_to_postfix(b);
    convert_to_postfix(c);
    convert_to_postfix(d);

}