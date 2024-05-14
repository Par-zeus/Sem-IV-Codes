#include <stdio.h>
int min(int a,int b);
void show(int c[][50],int v);

void main() {
  int i,j,k,u,v;
  printf("Enter the number of vertices:\n");
  scanf("%d",&v);
  int c[50][50],adj[50][50],dist[50][50];
  int source;
  for(i=1;i<=v;i++)
  {
      for(j=1;j<=v;j++)
      {
          if(i==j)
          {
              adj[i][j]=0;
          }
          else
          {
              printf("Is vertex %d adjacent to vertex %d?\n",j,i);
              printf("If yes enter the weight of the edge and if no enter 100\n");
              scanf("%d",&adj[i][j]);
          }
      }
  }
  printf("Enter the source vertex:\n");
  scanf("%d",&source);
  for(i=1;i<=v;i++)
  {
      dist[1][i]=adj[source][i];
  }
  
  for(k=2;k<=v-1;k++)
  {
      for(u=1;u<=v;u++)
      {
          if(u!=source)
          {
              dist[k][u]=dist[k-1][u];
              for(i=1;i<=v;i++)
              {
                  if(dist[k][u]>dist[k-1][i]+adj[i][u])
                        dist[k][u]=dist[k-1][i]+adj[i][u];
              }
          }
      }
      show(dist,v);
      printf("\n");
  }
} 

void show(int dist[][50],int v)
{
    int i,j;
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(dist[i][j]==100)
            {
                printf(" I");
            }
            else
            {
                printf("%3d",dist[i][j]);
            }
        }
        printf("\n");
    }
}
  
