#include <stdio.h>

long long getFactorialRecursive(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * getFactorialRecursive(n - 1);
}

int main() {
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    long long result = getFactorialRecursive(n);
    printf("Factorial of %d is: %lld\n", n, result);

    return 0;
}
