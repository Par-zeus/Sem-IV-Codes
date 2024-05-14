
#include <stdio.h>
#include <stdlib.h>

void nqueens(int r, int n, int column[]);
int place(int r, int c, int column[]);

int main() {
    int n, i;
    printf("Enter the number of queens:\n");
    scanf("%d", &n);
    int column[n];
    for (i = 0; i < n; i++) {
        column[i] = 0;
    }
    nqueens(1, n, column);
    return 0;
}

void nqueens(int r, int n, int column[]) {
    int i, c;
    for (c = 1; c <= n; c++) {
        if (place(r, c, column)) {
            column[r] = c;
            if (r == n) {
                // Print the board configuration
                printf("Solution:\n");
                for (i = 1; i <= n; i++) {
                    printf("(%d, %d) ", i, column[i]);
                }
                printf("\n");
            } else {
                nqueens(r + 1, n, column);
            }
        }
    }
}

int place(int r, int c, int column[]) {
    int j;
    for (j = 1; j < r; j++) {
        if (column[j] == c || abs(column[j] - c) == abs(j - r)) {
            return 0;
        }
    }
    return 1;
}