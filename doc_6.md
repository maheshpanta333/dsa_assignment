# Min and Max Heap Implementation

## Problem:
Given an array of data (unsorted), write a program to build the min and max heap.

## My Solution

### Files

- prog_6.c (contains heap functions and main function)

## Compile and Run
```bash
g++ prog_6.c -o heap_program
./heap_program
```

## What I did??<br>
Implemented heap data structure using array representation where the program takes user input for an unsorted array and builds both **max heap** and **min heap** from it. Created helper functions like **swap** for exchanging values, **minheapify** and **maxheapify** for maintaining heap properties recursively by comparing parent nodes with their children (left child at index 2*pos+1 and right child at 2*pos+2). The **build_max** and **build_min** functions start from the last non-leaf node (at index (n-1)/2) and heapify downwards to build complete heaps. Used dynamic memory allocation with malloc to create the array and properly freed it at the end!