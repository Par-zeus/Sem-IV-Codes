#include <stdio.h>

struct edge
{
 int u , v , wt ;
};
int path[50] ; 
int checkCycle(int u , int v , int wt);
void main()
{
 int n,m,mincost,i,j;
 int path[50];
 struct edge e[50];
 struct edge t;
 /* Creating graph of n vertices and m edges */
 printf("Enter the number of vertices in the graph: ");
 scanf("%d" , &n) ;
 printf("Enter the number of edges in the graph: ");
 scanf("%d" , &m) ;
 printf("Enter information for each edge of graph: \n");
 for(j=0 ; j<m ; j++)
 {
 printf("Enter the two edge vertices:\n ");
 printf("Enter the first edge:\n");
 scanf("%d" , &e[j].u) ;
  printf("Enter the second edge:\n");
 scanf("%d" , &e[j].v) ;
 printf("Enter the weight of the edge:\n");
 scanf("%d",&e[j].wt);
 }
 /* sorting the edges in ascending order of weights */
 for(i=0;i<m-1;i++)
 for(j=0;j<m-1-i;j++)
 if(e[j].wt > e[j+1].wt)
 {
 t=e[j]; e[j]=e[j+1]; e[j+1]=t;
 }
 /* Initializing the path array */
 for(i=1;i<=n;i++)
 path[i]=0;
 i=0; /* counts the number of edges selected in MST */
 j=0; /* counts the number of edges selected or discarded */
 mincost=0;
while(i!=n-1&&j!=m)
 {
 if( checkCycle( e[j].u , e[j].v , e[j].wt ) ) /* true if selected */
 {
 mincost=mincost + e[j].wt;
 i++;
 printf("Edge ( %d , %d ) with weight %d is selected \n", e[j].u , e[j].v , e[j].wt) ;
 }
 else
 printf("Edge ( %d , %d ) with weight %d is discarded \n", e[j].u , e[j].v , e[j].wt) ;
 j++;
 }
 if(i!=n-1)
 printf("Minimum Spanning tree cannot be formed");
 else
 printf("Minimum cost is %d \n" , mincost) ;
}
int checkCycle(int u , int v , int wt)
{
 while(path[u]>0)
 u=path[u];
 while(path[v]>0)
v=path[v];
 if(u!=v)
 {
 path[u]=v;
 return 1;
 }
 else
 return 0;
}

