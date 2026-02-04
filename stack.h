#pragma once
#include <stdbool.h>
#define MAX_SIZE 20

typedef struct stack{
    char key[MAX_SIZE];
    int top;
} Stack;

void initialise(Stack* s);
bool isempty(Stack* s);
void push(Stack* s,char c);
char pop(Stack*s);
void remove_pos(Stack*s, int x);
bool isfull(Stack* s);