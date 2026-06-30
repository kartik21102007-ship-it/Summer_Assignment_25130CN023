#include <stdio.h>
#include <math.h>
int is_prime(int num) {
    if (num <= 1) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }
    int limit = (int)sqrt(num);
    for (int i = 3; i <= limit; i += 2) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int start, end, count = 0;
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);
    printf("\nPrime numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
            count++;
        }
    }
    printf("\n\nTotal prime numbers found: %d\n", count);
    return 0;
}