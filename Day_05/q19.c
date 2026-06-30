#include <stdio.h>

void printFactors(int num) {
    if (num <= 0) {
        printf("Please enter a positive integer.\n");
        return;
    }

    printf("Factors of %d are: ", num);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a positive integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    printFactors(num);
    return 0;
}
