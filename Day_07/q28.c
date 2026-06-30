#include <stdio.h>

int reverseRecursiveHelper(int num, int rev) {
    if (num == 0) {
        return rev;
    }
    return reverseRecursiveHelper(num / 10, rev * 10 + (num % 10));
}

int reverseNumberRecursive(int num) {
    return reverseRecursiveHelper(num, 0);
}

int main() {
    int num;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Please enter a valid integer.\n");
        return 1;
    }

    int result = reverseNumberRecursive(num);
    printf("Reversed number: %d\n", result);

    return 0;
}
