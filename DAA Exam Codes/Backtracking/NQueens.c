#include <stdio.h>
#include <stdbool.h>
#define n 4

void print_board(int board[][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1)
            {
                printf(" Q ");
            }
            else
            {
                printf(" ✔ ");
            }
        }
        printf("\n");
    }
}

bool isSafe(int board[][n], int row, int col)
{
    int i, j;
    // check for same row
    for (i = 0; i < col; i++)
    {
        if (board[row][i])
            return false;
    }

    // check for upper triangle
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        // printf("%d %d \n",row,col);
        if (board[i][j])
            return false;
    }

    // check for lower triangle
    for (i = row, j = col; i < n && j >= 0; i++, j--)
    {
        if (board[i][j])
            return false;
    }
    return true;
}

bool Solve_until(int board[][n], int col)
{
    if (col >= n)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;

            if (Solve_until(board, col + 1))
                return true;
            // If placing the queen at board[i][col] doesn't lead to a solution,
            // then remove the queen from board[i][col]
            board[i][col] = 0;
        }
    }
    return false;
}

bool NQueens()
{
    int board[n][n] = {0};
    if (!Solve_until(board, 0))
    {
        printf("\nSolution Doesn't exist");
        return false;
    }

    print_board(board);
    return true;
}

int main()
{
    NQueens();
    return 0;
}