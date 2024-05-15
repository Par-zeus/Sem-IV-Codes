#include <stdio.h>
#include <stdlib.h>

int *matrix_dimensions;
int *bracket_before;
int *bracket_after;
int **c_table;
int **k_table;

void display_chain(int n)
{
    int i;
    bracket_before[1]--;
    bracket_after[n]--;
    for(i=1;i<=n;i++)
    {
        while(bracket_before[i]!=0)
        {
            printf("(");
            bracket_before[i]--;
        }
        printf("A%d",i);
        while(bracket_after[i]!=0)
        {
            printf(")");
            bracket_after[i]--;
        }
        if(i!=n)
        {
            printf("*");
        }
    }
}

int print_optimal_parentheses(int start_point, int end_point)
{
    if(start_point==end_point)
    {
        return 0;
    }
    else
    {
        bracket_before[start_point]++;
        bracket_after[end_point]++;
        print_optimal_parentheses(start_point, k_table[start_point-1][end_point-1]);
        print_optimal_parentheses(k_table[start_point-1][end_point-1] + 1, end_point);
    }
}

int main()
{
    int i,j,k;
    int n,step_size,min,val,min_at;

    printf("Enter the number of matrices: ");
    scanf("%d",&n);
    matrix_dimensions = (int*)calloc(n+1, sizeof(int));
    bracket_before = (int*)calloc(n+1, sizeof(int));
    bracket_after = (int*)calloc(n+1, sizeof(int));

    printf("Enter the...\n");
    printf("No of rows in matrix 1: ");
    scanf("%d",&matrix_dimensions[0]);
    for(i=1;i<n;i++)
    {
        printf("No of columns in matrix %d or no of rows in matrix %d: ",i,i+1);
        scanf("%d",&matrix_dimensions[i]);
    }
    printf("No of columns in matrix %d: ",n);
    scanf("%d",&matrix_dimensions[n]);

    c_table = (int**)calloc(n,sizeof(int*));
    k_table = (int**)calloc(n,sizeof(int*));
    for(i=0;i<n;i++)
    {
        c_table[i] = (int*)calloc(i+1,sizeof(int));
        k_table[i] = (int*)calloc(i+1,sizeof(int));
    }

    for(i=0;i<n;i++)
    {
        c_table[i][i] = 0;
    }

    for(step_size=1;step_size<n;step_size++)
    {
        for(i=1;i<=n-step_size;i++)
        {
            j=i+step_size;
            for(k=i;k<j;k++)
            {
                if(k==i)
                {
                    min = c_table[i-1][k-1]+c_table[k][j-1]+matrix_dimensions[i-1]*matrix_dimensions[k]*matrix_dimensions[j];
                    min_at = k;
                }
                else
                {
                    val = c_table[i-1][k-1]+c_table[k][j-1]+matrix_dimensions[i-1]*matrix_dimensions[k]*matrix_dimensions[j];
                    if(min>val)
                    {
                        min = val;
                        min_at = k;
                    }
                }
                c_table[i-1][j-1] = min;
                k_table[i-1][j-1] = min_at;
            }
        }
    }

    printf("\nC table\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>j)
            {
                printf(" \t");
            }
            else
            {
                printf("%d\t",c_table[i][j]);
            }
        }
        printf("\n");
    }

    printf("\nK table\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i>=j)
            {
                printf(" \t");
            }
            else
            {
                printf("%d\t",k_table[i][j]);
            }
        }
        printf("\n");
    }

    print_optimal_parentheses(1,n);
    printf("\nOptimal Order\n");
    display_chain(n);

    return 0;
}