#include <stdio.h>

void main()
{
 int v , i , j , min , c , current , nv , source , dest , y , x , T ;
 int INF=1000 ; /* Assuming 1000 to be the maximum weight */
 int visited[50] , path[50] , distance[50] ;
 int adj[50][50] ;

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
 printf("Enter the source vertex: ") ;
 scanf("%d" , &source) ;
 current=source ; 
 visited[current]=1 ;
 nv=1 ; 
 T=0 ;
while(nv!=v)
 {
/*Processing the adjacent vertices */
for(i=1 ; i<=v ; i++)
 if(adj[current][i]!=0)
 if(visited[i]!=1)
 if(distance[i]>adj[current][i]+T)
 {
 distance[i]=adj[current][i]+T ;
 path[i]=current ;
 }
/* Finding the closest vertex */
min=INF ;
for(i=1 ; i<=v ; i++)
 if(visited[i]!=1)
 if(distance[i]<min)
 {
 min=distance[i];
 current=i;
 }
visited[current]=1 ; nv=nv+1 ; T=distance[current] ;
 }
 printf("Enter the destination vertex:") ;
 scanf("%d" , &dest) ;
 printf("Shortest distance from source to destination vertex is %d \n",distance[dest]) ;
printf("Shortest path between source vertex %d and destination vertex %d is: \n",
 source,dest);
 y=dest;
 do
 {
 x=path[y];
 printf("Vertex %d is connected to vertex %d \n" , y , x) ;
 y=x;
 }
 while(y!=source) ;

}