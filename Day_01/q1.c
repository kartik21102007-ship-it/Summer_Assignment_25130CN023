#include <stdio.h>
int main() {
    int n, i;
    int sum = 0;
    printf("Enter value of n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        sum = sum + i;
    }
    printf("Sum of first %d numbers = %d\n", n, sum);
    return 0;
}