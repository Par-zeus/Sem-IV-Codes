#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define V 4

int min(int a, int b)
{
    return a < b ? a : b;
}

int max_bw_vertex(int max_bandwidth[], int visited[])
{

    int max_index;
    int max_bw = INT_MIN;

    for (int v = 0; v < V; v++)
    {
        if (!visited[v] && max_bandwidth[v] > max_bw)
        {
            max_index = v;
            max_bw = max_bandwidth[v];
        }
    }
    return max_index;
}
void max_bw_dj(int graph[V][V], int source, int destination)
{
    int max_bandwidth[V];
    int visited[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        max_bandwidth[i] = (i == source) ? INT_MAX : 0;
        visited[i] = 0;
        parent[i] = -1;
    }
    // Set maximum bandwidth to reach the source vertex as infinity
    max_bandwidth[source] = INT_MAX;

    for (int z = 0; z < V-1; z++)
    {
        int u = max_bw_vertex(max_bandwidth, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && graph[u][v] &&
                min(max_bandwidth[u], graph[u][v]) > max_bandwidth[v])
            {
                // Update max_bandwidth[v] to the minimum of max_bandwidth[u] and the bandwidth of the edge (u, v)
                max_bandwidth[v] = min(max_bandwidth[u], graph[u][v]);
                parent[v] = u;
            }
        }
    }
    if (max_bandwidth[destination] != INT_MIN)
    {
        printf("\nPath with maximum bandwidth from %d to %d : ", source, destination);
        int current = destination;
        while (current != -1)
        {
            printf("%d  ", current);
            current = parent[current];
        }
        printf("\nMaximum bandwidth : %d", max_bandwidth[destination]);
    }
    else
    {
        printf("\nNo path found from %d to %d\n", source, destination);
    }
}
int main()
{

    int graph[V][V] = {
        {0, 10, 5, 0},
        {0, 0, 9, 9},
        {0, 3, 0, 10},
        {0, 0, 0, 0}};
    int source = 0;
    int destination = 2;
    max_bw_dj(graph, source, destination);
    return 0;
}