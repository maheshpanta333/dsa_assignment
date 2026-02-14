#include <stdio.h>

#define MAX 10

// doing bfs with a queue
void bfs(int mat[MAX][MAX], int n, int start)
{
    int visit[MAX] = {0};
    int q[MAX];
    int head = 0, tail = 0;

    visit[start] = 1;
    q[tail++] = start;

    printf("BFS result: ");

    while (head < tail)
    {
        int now = q[head++];
        printf("%d ", now);

        for (int i = 0; i < n; i++)
        {
            // if connected and not seen yet
            if (mat[now][i] == 1 && visit[i] == 0)
            {
                visit[i] = 1;
                q[tail++] = i;
            }
        }
    }
    printf("\n");
}

// dfs using recursion logic
void dfs(int mat[MAX][MAX], int n, int current, int visit[])
{
    visit[current] = 1;
    printf("%d ", current);

    for (int i = 0; i < n; i++)
    {
        // go deeper if node is neighbor and not visited
        if (mat[current][i] == 1 && visit[i] == 0)
        {
            dfs(mat, n, i, visit);
        }
    }
}

int main()
{
    int nodes = 5;

    // simple matrix for the graph
    int myGraph[MAX][MAX] =
    {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 0, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 1, 1, 0}
    };

    int seen[MAX] = {0};

    // just printing the matrix first
    printf("The Matrix:\n");
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            printf("%d ", myGraph[i][j]);
        }
        printf("\n");
    }

    printf("\nStarting from vertex 0\n");
    bfs(myGraph, nodes, 0);

    printf("DFS result: ");
    dfs(myGraph, nodes, 0, seen);
    printf("\n");

    return 0;
}