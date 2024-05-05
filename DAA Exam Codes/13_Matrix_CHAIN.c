#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void parenthesis(int i, int j, int bracket[][10])
{
    if (i == j)
    {
        printf("A%d ", i);
        return;
    }
    printf("(");
    parenthesis(i, bracket[i][j], bracket);
    printf("*");
    parenthesis(bracket[i][j] + 1, j, bracket);
    printf(")");
}

int matrix_order(int p[], int n)
{
    int m[10][10];
    int brackets[10][10];

    for (int i = 1; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i < n - L + 1; i++)
        {
            int j = L + i - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + (p[i - 1] * p[j] * p[k]);

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                    brackets[i][j] = k;
                }
            }
        }
    }

    printf("\nPatterns of Matrix Mulltiplication: ");
    parenthesis(1, n - 1, brackets);
    printf("\n");

    return m[1][n - 1];
}
int main()
{
    int n;
    int mat[10];
    printf("\nEnter number of Matrices: ");
    scanf("%d", &n);
    printf("\nEnter the dimensions of matrices: ");
    for (int i = 0; i < n ; i++)
    {
        scanf("%d ", &mat[i]);
    }
    mat[n]=mat[n-1];
    int multiplymat = matrix_order(mat, n + 1);
    printf("Minimum number of scalar multiplications needed: %d\n", multiplymat);
    return 0;
}