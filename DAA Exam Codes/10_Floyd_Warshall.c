#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define Max_houses 100

void floyd_warshall(int graph[Max_houses][Max_houses], int num_houses)
{

    int dist[Max_houses][Max_houses];
    for (int i = 0; i < num_houses; i++)
    {
        for (int j = 0; j < num_houses; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < num_houses; k++)
    {
        for (int i = 0; i < num_houses; i++)
        {
            for (int j = 0; j < num_houses; j++)
            {
               if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX &&
               dist[i][k]+dist[k][j]<dist[i][j])
               {
                dist[i][j]=dist[i][k]+dist[k][j];
               }
            }
        }
    }

    printf("\nShortest Travell Time between Houses: \n");
      for (int i = 0; i < num_houses; i++)
    {
        for (int j = 0; j < num_houses; j++)
        {
            if(dist[i][j]==INT_MAX){
                printf("ERR");
            }else{
                printf("%d  ",dist[i][j]);
            }
        }
        printf("\n");
    }
}
int main()
{
    int num_houses, graph[Max_houses][Max_houses];
    printf("\nEnter the total number of houses: ");
    scanf("%d", &num_houses);
    printf("\nEnter travlling time between houses ");
    printf("\nPut -1 if unreachable\n");
    for (int i = 0; i < num_houses; i++)
    {
        for (int j = 0; j < num_houses; j++)
        {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1)
            {
                graph[i][j] = INT_MAX;
            }
        }
    }

    floyd_warshall(graph, num_houses);
    return 0;
}
