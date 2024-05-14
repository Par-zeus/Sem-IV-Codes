// Online C compiler to run C program online
#include <stdio.h>
int min(int a,int b);
void show(int c[][50],int v);

void main() {
  int i,j,k,v;
  printf("Enter the number of vertices:\n");
  scanf("%d",&v);
  int c[50][50],adj[50][50];
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
      
  for(i=1;i<=v;i++)
  {
      for(j=1;j<=v;j++)
      {
          c[i][j]=adj[i][j];
      }
  }
  
  for(k=1;k<=v;k++)
  {
      for(i=1;i<=v;i++)
      {
          for(j=1;j<=v;j++)
          {
              c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
          }
      }
      
      show(c,v);
      printf("\n");
  }
} 
  

int min(int a,int b)
{
    if(a>b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

void show(int c[][50],int v)
{
    int i,j;
    for(i=1;i<=v;i++)
    {
          for(j=1;j<=v;j++)
          {
              if(c[i][j]== -1)
              {
                  printf(" I");
              }
              else
              {
                  printf("%3d",c[i][j]);
              }
          }
          printf("\n");
      }
}
