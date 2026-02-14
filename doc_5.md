## Problem:
How can we implement an undirected graph using an adjacency matrix? Write a function that implements the BFS (Breadth-First Search) and DFS (Depth-First Search) techniques to traverse through the graph. Demonstrate the use of your program with an example graph.

---

## My Solution

### Files
- prog_5.c (contains BFS, DFS functions and main function)

---

## Compile and Run

```bash
g++ prog_5.c -o prog_5
./prog_5
```

## What I Did?

Implemented Graph Traversal Algorithms in C using an adjacency matrix representation for an undirected graph. The program demonstrates both BFS and DFS traversal techniques.

Used adjacency matrix where mat[i][j] = 1 indicates an edge exists between vertices i and j. Since the graph is undirected, the matrix is symmetric. Maximum graph size is defined as MAX = 10 vertices.

Implemented BFS using a queue-based approach with an array-based queue using head and tail pointers. The algorithm maintains a visit array to track visited vertices, starts from the given vertex, marks it as visited and enqueues it. While queue is not empty, it dequeues front vertex, prints it, and enqueues all unvisited adjacent vertices. This provides level-by-level traversal.

Implemented DFS using recursion. The algorithm marks current vertex as visited, prints it, and recursively visits all unvisited adjacent vertices. This goes as deep as possible before backtracking.

The program creates a 5-vertex undirected graph and displays the adjacency matrix before performing both BFS and DFS traversals starting from vertex 0.
