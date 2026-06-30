#include <stdio.h>

void printRepeatedCharacterPattern(int rows) {
    char ch = 'A';
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", ch);
        }
        ch++;
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

    printRepeatedCharacterPattern(rows);
    return 0;
}
