#include <stdio.h>

long long getLargestPrimeFactor(long long num) {
    if (num <= 1) return -1;

    long long maxPrime = -1;

    while (num % 2 == 0) {
        maxPrime = 2;
        num /= 2;
    }

    while (num % 3 == 0) {
        maxPrime = 3;
        num /= 3;
    }

    for (long long i = 5; i * i <= num; i += 6) {
        while (num % i == 0) {
            maxPrime = i;
            num /= i;
        }
        while (num % (i + 2) == 0) {
            maxPrime = i + 2;
            num /= (i + 2);
        }
    }

    if (num > 4) {
        maxPrime = num;
    }

    return maxPrime;
}

int main() {
    long long num;

    printf("Enter a positive integer: ");
    if (scanf("%lld", &num) != 1 || num <= 1) {
        printf("Please enter a valid integer greater than 1.\n");
        return 1;
    }

    long long result = getLargestPrimeFactor(num);
    printf("The largest prime factor of %lld is: %lld\n", num, result);

    return 0;
}
