//User defined function of kruskal algorithm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int kruskal(int **graph, int n, int *parent, int *rank)
{
    int i, j, u, v, w, min, u_root, v_root, count = 0;
    int *visited = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
        parent[i] = i;
        rank[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        min = 999;
        for (j = 0; j < n; j++)
        {
            if (visited[j] == 0 && graph[j][0] < min)
            {
                min = graph[j][0];
                u = j;
                v = graph[j][1];
                w = graph[j][2];
            }
        }
        u_root = find(u, parent);
        v_root = find(v, parent);
        if (u_root != v_root)
        {
            count++;
            printf("Edge %d-%d: %d\n", u, v, w);
            union1(u, v, parent, rank);
        }
        visited[u] = 1;
    }
    return count;
}
int find(int i, int *parent)
{
    if (parent[i] == i)
        return i;
    return find(parent[i], parent);
}
void union1(int x, int y, int *parent, int *rank)
{
    int x_root = find(x, parent);
    int y_root = find(y, parent);
    if (rank[x_root] < rank[y_root])
        parent[x_root] = y_root;
    else if (rank[x_root] > rank[y_root])
        parent[y_root] = x_root;
    else
    {
        parent[y_root] = x_root;
        rank[x_root]++;
    }
}
int main()
{
    int i, j, n, temp, u, v, w, count;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int **graph = (int **)malloc(sizeof(int *) * n);
    for (i = 0; i < n; i++)
    {
        graph[i] = (int *)malloc(sizeof(int) * 3);
    }
    printf("Enter the edges and their weights: \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
    int *parent = (int *)malloc(sizeof(int) * n);
    int *rank = (int *)malloc(sizeof(int) * n);
    count = kruskal(graph, n, parent, rank);
    printf("\nTotal number of edges: %d\n", count);
    return 0;
}