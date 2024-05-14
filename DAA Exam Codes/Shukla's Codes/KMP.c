#include <stdio.h>
#include <string.h>
void KMP(char T[] , char P[]);
void longest_prefix_suffix(char P[] , int f[]);
void main()
{
 char T[100] , P[100];
 printf("Enter the Text string: ");
scanf("%s",T);
 printf("Enter the Pattern string: ");
 scanf("%s",P);
 KMP(T,P);
}
void KMP(char T[] , char P[])
{
 int i,j,m,n;
 int f[100];
 longest_prefix_suffix(P,f);
 m = strlen(P);
 n = strlen(T);
 i = 0;
 j=0;
 while(i < n)
 {
 if(P[j] == T[i])
 {
 j++;
 i++;
 }
 if (j == m)
 {
 printf("Pattern found at position %d \n", i-j);
 j = f[j-1];
 }
 else if(P[j] != T[i])
 {
 if(j != 0)
 j = f[j-1];
 else
 i = i+1;
 }
 }
}
void longest_prefix_suffix(char P[] , int f[])
{
 int i,j,m;
 m=strlen(P);
 j=0;
 i=1;
 f[0]=0;
 while(i < m)
 {
 if(P[i] == P[j])
 {
 f[i]=j+1;
 i++;
 j++;
 }
 else
 {
 if( j != 0 )
 j=f[j-1];
 else
 {
 f[i]=0;
 i++;
 }
 }
 }
 printf("Prefix Suffix Array is as shown:\n");
 for(i=0;i<m;i++)
 printf("%d ",f[i]);
 printf("\n");
}
