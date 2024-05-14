#include<stdio.h>
int min(int a,int b);
void main()
{
    int c[20][20];
    int i,j,no,denomination[20],amount,temp;
    printf("Enter the amount:\n");
    scanf("%d",&amount);
    printf("Enter the number of denominations of coin:\n");
    scanf("%d",&no);
  
#include<stdio.h>
#define INF 999999

int min(int a,int b);

void main()
{
    int c[20][20];
    int i,j,no,denomination[20],amount,temp;
    printf("Enter the amount:\n");
    scanf("%d",&amount);
    printf("Enter the number of denominations of coin:\n");
    scanf("%d",&no);
  
    for(i=0;i<no;i++)
    {
        printf("Enter the denomination:\n");
        scanf("%d",&denomination[i]);
    }
    
    for(i=0;i<=no;i++) // Initialize c array
    {
        for(j=0;j<=amount;j++)
        {
            if(j == 0)
                c[i][j] = 0;
            else
                c[i][j] = INF;
        }
    }
    
    for(i=1;i<=no;i++)
    {
        for(j=1;j<=amount;j++)
        {
            if(denomination[i-1] <= j)
                c[i][j] = min(c[i-1][j], 1 + c[i][j - denomination[i-1]]);
            else
                c[i][j] = c[i-1][j];
        }
    }
    
    printf("\nThe least number of coins required to pay %d are %d\n",amount,c[no][amount]);
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