#include <stdio.h>

int getFibonacciRecursive(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return getFibonacciRecursive(n - 1) + getFibonacciRecursive(n - 2);
}

int main() {
    int n;

    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    int result = getFibonacciRecursive(n);
    printf("The %d-th Fibonacci term is: %d\n", n, result);

    return 0;
}
