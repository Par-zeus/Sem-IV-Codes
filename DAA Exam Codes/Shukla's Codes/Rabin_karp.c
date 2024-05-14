#include <stdio.h>
#include <string.h>
#include <math.h>
#define d 256 /* Alphabet size */
void rabin(char T[] , char P[]);
void main()
{
 char T[100] , P[100];
 printf("Enter the Text string: ");
scanf("%s",T);
 printf("Enter the Pattern string: ");
 scanf("%s",P);
 rabin(T,P);
}
void rabin(char T[] , char P[])
{
 int i , j , n , m , p , q , t , h ;
 n=strlen(T);
 m=strlen(P);
 q=7; /* Prime number */
 p=0; 
 t=0; 
 
 h=((int) pow(d,m-1)) % q ;
/* Obtaining hash values */
 for(i=0 ; i<m ; i++)
 {
 p=(d*p+P[i])%q;
 t=(d*t+T[i])%q;
 }
 for(i=0;i<=n-m;i++) /* going through text T*/
 {
 /* Check if the current sliding window of text and pattern have same hash values */
 if(t==p)
 {
 /* Check if all characters are same or whether it's a SPURIOUS HIT ! */
 for(j=0;j<m;j++)
 if(T[i+j]!=P[j])
 break;
 if(j==m) /* Match found */
 printf("Pattern found at index %d \n",i);
 }
 /* Compute the next sliding window for the text using previous value. */
 if(i<n-m)
 t = (d*(t - h*T[i]) + T[i+m]) % q;
 /* We might get negative value of t, converting it to positive */
 if(t < 0)
 t = (t + q);
 }
}

