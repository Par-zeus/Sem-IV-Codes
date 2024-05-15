#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int table[n + 1][W + 1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                table[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                table[i][w] = max(val[i - 1] + table[i - 1][w - wt[i - 1]], table[i - 1][w]);
            }
            else
            {
                table[i][w] = table[i - 1][w];
            }
        }
    }
    return table[n][W];
}

int main()
{
    int profit[] = {3,4,6,5};
    int weight[] = {2,3,5,4};
    int W = 5;
    int n = sizeof(profit) / sizeof(profit[0]);
    printf("maximum profit:%d", knapSack(W, weight, profit, n));
    return 0;
}
