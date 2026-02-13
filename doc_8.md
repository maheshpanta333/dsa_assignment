## Problem:
Write a program that generates a list of **N random integers** in the range **[1, 1000]**, where **N** is provided by the user at runtime. Then:

- Ask the user to choose one sorting algorithm:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
- Sort the generated numbers using the chosen algorithm.
- Print the numbers **before and after sorting**.
- Display the total number of **comparisons and swaps (or moves)** performed by the selected algorithm.

---

## My Solution

### Files

- prog_sort.c (contains all sorting functions and the main function)

---

## Compile and Run

```bash
g++ prog_8.c -o sort_program
./sort_program
```

## What I Did?<br>
Implemented a Sorting Calculator in C that dynamically generates an array of random integers in the range [1,1000] based on user input size. The program provides a menu-driven interface where the user selects one of four sorting algorithms: Bubble Sort, Selection Sort, Insertion Sort, or Merge Sort.

Each sorting algorithm is implemented as a separate function. I created a helper function swap() for exchanging values and a display() function to print arrays neatly. The program tracks and displays the total number of comparisons and swaps (or moves) performed during sorting for performance analysis.

For Merge Sort, I implemented a divide-and-conquer strategy:

Recursively divide the array into halves using mergesort().

Merge sorted subarrays using the merge() function with temporary dynamically allocated arrays.

Count comparisons during merging.

Dynamic memory allocation is handled using malloc, realloc, and free to allow runtime resizing of the array. The program runs in a loop until the user selects the Exit option.