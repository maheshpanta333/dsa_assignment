## Problem:
Given a **weighted graph**, implement **Dijkstra's algorithm** to find the shortest path from a **source node** to **all other nodes**.

**Requirements:**
- Create a weighted graph with multiple nodes and edges
- Implement Dijkstra's algorithm to compute shortest paths
- Display the shortest distance from source to each node
- Show the complete path from source to each destination node
- Handle disconnected nodes (no path exists)

---

## My Solution

### Files
- **prog_7.c** (contains graph structure, Dijkstra's algorithm, and main function)

---

## Compile and Run

```bash
gcc prog_7.c -o dijkstra_program
./dijkstra_program
```

---

## What I Did?

Implemented **Dijkstra's Shortest Path Algorithm** in C using an adjacency matrix representation for a weighted, undirected graph.

### Graph Structure:
- Created a `Graph` structure with an adjacency matrix (`adj[MAX][MAX]`) to store edge weights
- Used `INF` (999999) to represent no direct edge between nodes
- Maximum graph size is defined as `MAX = 10` nodes

### Key Functions:

1. **`createGraph(int n)`**: 
   - Dynamically allocates and initializes a graph with `n` nodes
   - Sets diagonal elements to 0 (distance from node to itself)
   - Sets all other entries to `INF` (no edge initially)

2. **`addEdge(struct Graph *g, int u, int v, int w)`**: 
   - Adds a weighted edge between nodes `u` and `v` with weight `w`
   - Since the graph is undirected, sets both `adj[u][v]` and `adj[v][u]`

3. **`findMin(int dist[], bool seen[], int n)`**: 
   - Helper function to find the unvisited node with minimum distance
   - Returns the index of the node with smallest tentative distance
   - Returns -1 if all reachable nodes are visited

4. **`doDijkstra(struct Graph *g, int start)`**: 
   - **Core implementation** of Dijkstra's algorithm
   - Maintains three arrays:
     - `dist[]`: Shortest distance from source to each node
     - `prev[]`: Previous node in the shortest path (for path reconstruction)
     - `seen[]`: Boolean array tracking visited nodes
   - **Algorithm steps:**
     1. Initialize all distances to `INF` except source (distance = 0)
     2. For each iteration, select unvisited node with minimum distance
     3. Mark selected node as visited
     4. Update distances to all unvisited neighbors if shorter path found
     5. Repeat until all nodes processed
   - **Path reconstruction:** Traces back through `prev[]` array from destination to source
   - Prints both the shortest distance and the complete path for each node