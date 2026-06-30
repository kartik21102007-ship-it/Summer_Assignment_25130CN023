#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[100][100], b[100][100], sum[100][100];

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("\nEnter elements of 1st matrix:\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of 2nd matrix:\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            scanf("%d", &b[i][j]);
        }
    }

    // Adding corresponding elements of two matrices
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nSum of the two matrices is:\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}