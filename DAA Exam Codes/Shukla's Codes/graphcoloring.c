#include <stdio.h>
#include <stdbool.h>

int n, m;
int adj[20][20];
int x[20];

// Function prototypes
void colorvertex(int k);
int findcolor(int k);

int main() {
    int i, j;
    printf("Enter the number of vertices in the graph:\n");
    scanf("%d", &n);
    printf("Enter the chromatic number of the graph:\n");
    scanf("%d", &m);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            if (i == j) {
                adj[i][j] = 0;
            } else {
                printf("Is vertex %d adjacent to vertex %d:\n", j, i);
                printf("If yes enter 1 of the edge and if no enter 0:\n");
                scanf("%d", &adj[i][j]);
            }
        }
    }
    for (i = 1; i <= n; i++) {
        x[i] = 0;
    }
    colorvertex(1);
    return 0;
}

void colorvertex(int k) {
    int i;
    while (true) {
        findcolor(k);

        if (x[k] == 0) {
            return;
        }
        if (k == n) {
            printf("The solution is:\n");
            for (i = 1; i <= n; i++) {
                printf("(%d, %d) ", i, x[i]);
            }
            printf("\n");
        } else {
            colorvertex(k + 1);
        }
    }
}

int findcolor(int k) {
    int j;
    while (true) {
        x[k] = (x[k] + 1) % (m + 1);

        if (x[k] == 0) {
            return 0;
        }
        for (j = 1; j <= n; j++) {
            if ((adj[k][j] != 0) && (x[k] == x[j])) {
                break;
            }
        }
        if (j == n + 1) {
            return 0;
        }
    }
}
