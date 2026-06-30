#include <stdio.h>

void printReverseNumberTriangle(int rows) {
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

int main() {
    int rows;

    printf("Enter number of rows: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printReverseNumberTriangle(rows);
    return 0;
}
