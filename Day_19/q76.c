#include <stdio.h>

int main() {
    int n, i, j, main_sum = 0, sec_sum = 0;
    int mat[100][100];

    printf("Enter the size of the square matrix (n x n): ");
    scanf("%d", &n);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; ++i) {
        for (j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n; ++i) {
        main_sum += mat[i][i];
        sec_sum += mat[i][n - i - 1];
    }

    printf("Sum of the main diagonal: %d\n", main_sum);
    printf("Sum of the secondary diagonal: %d\n", sec_sum);

    return 0;
}