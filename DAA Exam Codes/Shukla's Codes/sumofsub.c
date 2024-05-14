#include <stdio.h>

void sumOfSub(int s , int k , int r) ;
int x[50] , w[50] , m , n ;
void main()
{ 
 int i , r=0 ;

 printf("Enter the number of elements: ") ;
 scanf("%d" , &n) ;
 printf("Enter m: ") ;
 scanf("%d" , &m) ;
 printf("Enter the weight of each element: \n") ;
 for(i=1 ; i<=n ; i++)
 {
 scanf("%d" , &w[i]) ;
 r=r+w[i] ;
 }
 printf("Solutions are as shown: \n") ;
 sumOfSub(0,1,r) ;

}
void sumOfSub(int s , int k , int r)
{
 int i ;
 x[k]=1 ;
 if(s+w[k]==m)
 {
 for(i=1 ; i<=k ; i++)
 printf("%d " , x[i]) ;
for(i=k+1 ; i<=n ; i++)
 printf("0 ") ;
printf("\n");
 }
 else if(s+w[k]+w[k+1]<=m)
sumOfSub(s+w[k] , k+1 , r-w[k]) ;
 if( (s+r-w[k]>=m) && (s+w[k+1]<=m) )
 {
 x[k]=0;
 sumOfSub(s,k+1,r-w[k]) ;
 }
}
