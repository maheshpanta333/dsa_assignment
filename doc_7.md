## Problem:
Given a weighted graph, implement Dijkstra's algorithm to find the shortest path from a source node to all other nodes.

---

## My Solution

### Files
- prog_7.c (contains graph structure, Dijkstra's algorithm, and main function)

---

## Compile and Run

```bash
g++ prog_7.c -o prog_7
./prog_7
```

## What I Did?

Implemented Dijkstra's Shortest Path Algorithm in C using an adjacency matrix representation for a weighted, undirected graph.

Created a Graph structure with an adjacency matrix to store edge weights. Used INF (999999) to represent no direct edge between nodes. Maximum graph size is defined as MAX = 10 nodes.

The createGraph function dynamically allocates and initializes a graph with n nodes, sets diagonal elements to 0 (distance from node to itself), and sets all other entries to INF. The addEdge function adds a weighted edge between nodes, and since the graph is undirected, it sets both directions.

Implemented the core Dijkstra's algorithm in the doDijkstra function. The algorithm maintains three arrays: dist[] for shortest distance from source to each node, prev[] for previous node in the shortest path (used for path reconstruction), and seen[] boolean array tracking visited nodes.

The algorithm works by initializing all distances to INF except source (distance = 0). For each iteration, it selects the unvisited node with minimum distance using the findMin helper function, marks it as visited, and updates distances to all unvisited neighbors if a shorter path is found through the current node. This process repeats until all nodes are processed.

For path reconstruction, the algorithm traces back through the prev[] array from destination to source. The program prints both the shortest distance and the complete path for each node, or displays "No path" for unreachable nodes.

The sample graph created has 6 nodes with weighted edges between them, and the algorithm runs from node 2 as the source. Graph structure is dynamically allocated using malloc and properly freed at program end.
