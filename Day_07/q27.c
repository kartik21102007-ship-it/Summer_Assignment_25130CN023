#include <stdio.h>

int getSumOfDigitsRecursive(int num) {
    if (num < 0) {
        num = -num;
    }
    if (num == 0) {
        return 0;
    }
    return (num % 10) + getSumOfDigitsRecursive(num / 10);
}

int main() {
    int num;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Please enter a valid integer.\n");
        return 1;
    }

    int result = getSumOfDigitsRecursive(num);
    printf("Sum of digits: %d\n", result);

    return 0;
}
