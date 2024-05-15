#include <stdio.h>

void strassen(int A[2][2], int B[2][2], int result[2][2]) {
    int P1, P2, P3, P4, P5, P6, P7;

    P1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    P2 = (A[1][0] + A[1][1]) * B[0][0];
    P3 = A[0][0] * (B[0][1] - B[1][1]);
    P4 = A[1][1] * (B[1][0] - B[0][0]);
    P5 = (A[0][0] + A[0][1]) * B[1][1];
    P6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    P7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    result[0][0] = P1 + P4 - P5 + P7;
    result[0][1] = P3 + P5;
    result[1][0] = P2 + P4;
    result[1][1] = P1 - P2 + P3 + P6;
}

int main() {
    int A[2][2] = {{1, 2}, {3, 4}};
    int B[2][2] = {{5, 6}, {7, 8}};
    int result[2][2];

    strassen(A, B, result);

    printf("Strassen's Matrix Multiplication Result:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}