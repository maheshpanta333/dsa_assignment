#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10
#define INF 999999 // using a big number instead of INT_MAX for simplicity

struct Graph {
    int n;
    int adj[MAX][MAX];
};

// make graph empty
struct Graph* createGraph(int n) {
    struct Graph *g = malloc(sizeof(struct Graph));
    g->n = n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) g->adj[i][j] = 0;
            else g->adj[i][j] = INF;
        }
    }
    return g;
}

// put weights between nodes
void addEdge(struct Graph *g, int u, int v, int w) {
    g->adj[u][v] = w;
    g->adj[v][u] = w; // its undirected graph so both side
}

// find which node is closest and not visited yet
int findMin(int dist[], bool seen[], int n) {
    int min = INF;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (!seen[i] && dist[i] <= min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void doDijkstra(struct Graph *g, int start) {
    int n = g->n;
    int dist[MAX];
    int prev[MAX];
    bool seen[MAX];

    // init arrays
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
        seen[i] = false;
    }
    
    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = findMin(dist, seen, n);
        if (u == -1) break;

        seen[u] = true;

        // check neighbors
        for (int v = 0; v < n; v++) {
            // update dist if we find better way through u
            if (!seen[v] && g->adj[u][v] != INF && dist[u] != INF 
                && dist[u] + g->adj[u][v] < dist[v]) {
                
                dist[v] = dist[u] + g->adj[u][v];
                prev[v] = u;
            }
        }
    }

    // print the final result
    printf("Shortest paths from %d:\n", start);
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF) {
            printf("Node %d: No path\n", i);
        } else {
            printf("Node %d: Cost %d, Path: ", i, dist[i]);
            
            // tracing back the path
            int temp[MAX];
            int curr = i;
            int top = 0;
            while (curr != -1) {
                temp[top++] = curr;
                curr = prev[curr];
            }
            for (int j = top - 1; j >= 0; j--) {
                printf("%d%s", temp[j], (j == 0 ? "" : "->"));
            }
            printf("\n");
        }
    }
}

int main() {
    struct Graph *g = createGraph(6);

    addEdge(g, 0, 1, 5);
    addEdge(g, 0, 2, 2);
    addEdge(g, 1, 3, 6);
    addEdge(g, 2, 1, 1);
    addEdge(g, 2, 4, 4);
    addEdge(g, 3, 4, 2);
    addEdge(g, 3, 5, 7);
    addEdge(g, 4, 5, 3);

    doDijkstra(g, 2);

    free(g);
    return 0;
}