#include <stdio.h>
#include <string.h>

int max(int a, int b);

int main() {
    char x[20], y[20];
    int n = 0, m = 0, i, j;
    int c[20][20];
    
    printf("Enter the first string:\n");
    scanf("%s", x);
    printf("Enter the second string:\n");
    scanf("%s", y);

    n = strlen(x);
    m = strlen(y);

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (x[i - 1] == y[j - 1])
                c[i][j] = 1 + c[i - 1][j - 1];
            else
                c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }

    printf("Length Matrix:\n");
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }

    // Reconstructing the LCS
    i = n;
    j = m;
    int index = c[n][m];
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the null terminator

    while (i > 0 && j > 0) {
        if (x[i - 1] == y[j - 1]) {
            lcs[index - 1] = x[i - 1];
            i--;
            j--;
            index--;
        } else if (c[i - 1][j] > c[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Printing the LCS
    printf("Longest Common Subsequence: %s\n", lcs);

    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}
