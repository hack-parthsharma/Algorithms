//User defined function for prims algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int prims(int **graph, int n, int *parent, int *key)
{
    int i, j, u, v, w, min, u_root, v_root, count = 0;
    int *visited = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        parent[i] = i;
        key[i] = 999;
    }
    key[0] = 0;
    for (i = 0; i < n - 1; i++)
    {
        min = 999;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && key[j] < min)
            {
                min = key[j];
                u = j;
            }
        }
        visited[u] = 1;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && graph[u][j] < key[j])
            {
                key[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (i != parent[i])
        {
            count++;
            printf("Edge %d-%d: %d\n", i, parent[i], graph[i][parent[i]]);
        }
    }
    return count;
}
int main()
{
    int i, j, n, temp, flag = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * n);
        for (j = 0; j < n; j++)
            graph[i][j] = 999;
    }
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &graph[i][i]);
    for (i = 0; i < n - 1; i++)
    {
        printf("Enter the edge %d: ", i + 1);
        scanf("%d %d %d", &graph[i][i + 1], &graph[i + 1][i], &graph[i][i + 1]);
    }
    int *parent = (int *)malloc(sizeof(int) * n);
    int *key = (int *)malloc(sizeof(int) * n);
    printf("The MST is: ");
    prims(graph, n, parent, key);
    return 0;
}