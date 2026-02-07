# Doubly Linked List Implementation

# Problem:
Create a doubly linked list in C that supports inserting nodes at the end and traversing the list in reverse order using a tail pointer.

# My Solution

## Files

- prog_3.c (contains node struct, list logic, and main function)

## Compile and Run

```bash
g++ prog_3.c -o prog_3
./prog_3
```

## What I did??<br>
Created two structures one for node another for list with head and tail pointer to track end and beginning of the list for the traversal and then used **insertatend** function to add values into the list as nodes where **createnode** function would return a node with *key, next pointer and prev pointer* and replaces the tail pointer of the list everytime and then reversal traversal works with starting with tail to head using *prev* pointer from each node and then clearning the occupied memory!