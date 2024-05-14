#include <stdio.h>

int max(int x , int y)
{
if(x>y)
 return x ;
else
 return y ;
}
void main()
{
 int i , j , n , m ;
 int p[50] , w[50] , v[50][50];

 printf("Enter the number of objects: ") ;
 scanf("%d" , &n) ;
 printf("Enter the Knapsack capacity: ") ;
 scanf("%d" , &m) ;
 printf("Enter the profit and weight of each object:") ;
 for(i=1 ; i<=n ; i++)
 {
 printf("\nProfit of object No. %d will be -- " , i) ;
 scanf("%d" , &p[i]) ;
 printf("Weight of object No. %d will be -- " , i) ;
 scanf("%d" , &w[i]) ;
 }
 for(i=0 ; i<=n ; i++)
 v[i][0]=0;
 for(j=0 ; j<=n ; j++)
 v[0][j]=0;
 for(i=1 ; i<=n ; i++)
 for(j=1 ; j<=m ;j++)
if(i==1)
if(j<w[1])
v[1][j]=0;
else
v[1][j]=p[1];
else if(j<w[i])
v[i][j] = v[i-1][j];
 else
 v[i][j]=max(v[i-1][j] , v[i-1][ j-w[i] ] + p[i] );
 printf("\nMaximum profit earned will be %d \n" , v[n][m]) ;
printf("\nValue table is as shown \n") ;
 for(i=0 ; i<=n ; i++)
 {
 for(j=0 ; j<=m ;j++)
printf("%5d", v[i][j]);
 printf("\n");
 }
 printf("\n Objects included in knapsack are: ");
 i = n ; j = m ;
 while(i>0 && j > 0)
 {
 if(v[i][j] != v[i-1][j])
 {
 printf("%d ", i);
 j = j - w[i];
 i = i - 1;
 }
 else
 i = i - 1;
 }

}

