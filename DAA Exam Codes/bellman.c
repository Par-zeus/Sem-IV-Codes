#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

void BellmanFord(int graph[][3],int V,int E,int src){
    int dist[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;
    }
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int j=0;j<E;j++){

            int x=graph[j][0];
            int y=graph[j][1];
            int wt=graph[j][2];

            if(dist[x]!=INT_MAX && dist[x]+wt<dist[y]){
                dist[y]=dist[x]+wt;
            }
        }
    }


    for (int j = 0; j < E; j++)
    {
        int x=graph[j][0];
            int y=graph[j][1];
            int wt=graph[j][2];

            if(dist[x]!=INT_MAX && dist[x]+wt<dist[y]){
                printf("\nGraph contains a negative edge cycle\n");
                return;
            }
    }

    printf("\nVertex distance from source\n");
    for(int i=0;i<V;i++){
        printf("%d\t%d\n",i,dist[i]);
    }
    
}
int main(){
    int V=7,E=10;
     int graph[][3] = {
        {0, 1, 6},
        {0, 2, 5},
        {0, 3, 5},
        {3, 2, -2},
        {2, 1, -2},
        {1, 4, -1},
        {2, 4, 1},
        {3, 5, -1},
        {4, 6, 3},
        {5, 6, 3}};

    BellmanFord(graph, V, E, 0);
    return 0;
}