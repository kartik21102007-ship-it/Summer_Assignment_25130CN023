#include <stdio.h>

void printFibonacci(int n) {
    long long first = 0, second = 1, next;

    printf("Fibonacci Series: ");

    for (int i = 0; i < n; i++) {
        printf("%lld ", first);
        next = first + second;
        first = second;
        second = next;
    }
    printf("\n");
}

int main() {
    int terms;

    printf("Enter the number of terms: ");
    if (scanf("%d", &terms) != 1 || terms <= 0) {
        printf("Please enter a valid positive integer.\n");
        return 1;
    }

    printFibonacci(terms);
    return 0;
}