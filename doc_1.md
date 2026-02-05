# Given Problem:
1. Write a program to check if any given mathematical expression has a balanced number of
parentheses or not?
Run the program by testing following expression-
⇒a + (b − c) ∗ (d
⇒m + [a − b ∗ (c + d ∗ {m)]
⇒a + (b − c)
Hint: Use stack

# What I did?
I created a header file *stack.h* that uses *stack.c* file implementing stack that I can use later!<br>
After which I created the check_balance function that would take the expression and print the statement that either the given expression is **balanced** or not! <BR>

## Logic behind
The function *check_balanced* takes the string of the expression and then uses stack to push brackets into it and then compare every expression to look for closing brackedts if we have opening bracket in the top of the stack and at the end of the loop we see if there is no element in the stack we know it is *balanced*.<br>
So we push brackets into the stack and then just look for the closing of the bracket in the expression itself and pop it out!
We use **is_match** function that takes the stack's top and then the character at the particular iteration and compares to see if there is pair of opening and closing parantheses and returns boolean value according to it and on its basis we decide if we pop or not!

### HOW TO RUN THE SOLUTION
```
g++ prog_1.c stack.c -o prog_1 
./prog_1
```