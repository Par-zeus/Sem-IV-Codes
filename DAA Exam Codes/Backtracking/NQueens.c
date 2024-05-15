#include <stdio.h>
#include <stdlib.h>

int place(int r, int c, int column[])
{
    for (int j = 1; j < r; j++)
    {
        if (column[j] == c || abs(column[j] - c) == abs(j - r))
            return 0;
    }
    return 1;
}

int printboard(int n, int column[])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (column[i] == j)
            {
                printf(" Q ");
            }
            else
            {
                printf(" . ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void nqueens(int r, int n, int column[], int *flag)
{
    // printf("\nSolution %d",*(++flag));
    for (int c = 1; c <= n; c++)
    {
        if (place(r, c, column))
        {
            column[r] = c;

            if (r == n)
            {
                printboard(n, column);
                *flag = 1;
            }
            else
            {
                nqueens(r + 1, n, column, flag);
            }
        }
    }
}

int main()
{
    int n;
    printf("\nEnter the number of queens: ");
    scanf("%d", &n);
    int column[n];
    int flag = 0; // Initialize flag
    for (int i = 0; i < n; i++)
    {
        column[i] = 0;
    }
    nqueens(1, n, column, &flag);
    if (!flag) // Check if no solution is found
    {
        printf("\nNo solution found.\n");
    }
    return 0;
}
