#include <stdio.h>

void main()
{
 int v , i , j , min , c , current , nv ;
 int INF=1000 ; /* Assuming 1000 to be the maximum weight */
 int visited[50] , path[50] , distance[50] ;
 int adj[50][50];

 /* Creating graph of v vertices */
 printf("Enter the number of vertices in the graph: ");
 scanf("%d" , &v) ;
for(i=1; i<=v ; i++)
 for(j=1 ; j<=v ; j++)
 {
 printf("Is vertex %d adjacent to vertex %d ? " , j , i) ;
 printf("Enter weight of edge if yes and 0 if no : ");
 scanf("%d" , &adj[i][j]) ;
 }
 /* Initializing the 3 arrays */
 for(i=1 ; i<=v ; i++)
 {
 visited[i]=0 ;
 path[i]=0 ;
 distance[i]=INF ;
 }
 current=1 ; visited[current]=1 ; nv=1 ;
 while(nv!=v)
 {
/*Processing the adjacent vertices */
for(i=1 ; i<=v ; i++)
 if(adj[current][i]!=0)
 if(visited[i]!=1)
 if(distance[i]>adj[current][i])
 {
 distance[i]=adj[current][i];
 path[i]=current;
 }
/* Finding the closest vertex */
min=INF;
for(i=1 ; i<=v ; i++)
 if(visited[i]!=1)
 if(distance[i]<min)
 {
 min=distance[i] ;
 current=i ;
 }
visited[current]=1 ;
nv=nv+1 ;
}
 /* Finding minimum cost */
 c=0;
 for(i=2 ; i<=v ; i++)
c=c+distance[i] ;
 printf("Minimum cost is %d \n" , c) ;
 /*Displaying the spanning tree*/
 for(i=2 ; i<=v ; i++)
 printf("Vertex %d is connected to vertex %d \n" , i , path[i]);

}
