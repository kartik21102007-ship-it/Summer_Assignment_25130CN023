#include <stdio.h>

int main() {
    int r, c, i, j;
    int a[100][100], trans[100][100];

    printf("Enter the number of rows: ");
    scanf("%d", &r);
    printf("Enter the number of columns: ");
    scanf("%d", &c);

    printf("\nEnter elements of matrix:\n");
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            trans[j][i] = a[i][j];
        }
    }

    printf("\nTranspose of the matrix is:\n");
    for (i = 0; i < c; ++i) {
        for (j = 0; j < r; ++j) {
            printf("%d ", trans[i][j]);
        }
        printf("\n");
    }

    return 0;
}