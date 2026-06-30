#include <stdio.h>

void printHollowSquare(int size) {
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int size;

    printf("Enter side length of square: ");
    if (scanf("%d", &size) != 1 || size <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printHollowSquare(size);
    return 0;
}
