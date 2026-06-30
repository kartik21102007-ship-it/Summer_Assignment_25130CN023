#include <stdio.h>

long long getNthFibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;

    long long first = 0, second = 1, next = 0;

    for (int i = 2; i <= n; i++) {
        next = first + second;
        first = second;
        second = next;
    }
    return second;
}

int main() {
    int n;

    printf("Enter the value of n: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    printf("The %d-th Fibonacci term is: %lld\n", n, getNthFibonacci(n));
    return 0;
}
