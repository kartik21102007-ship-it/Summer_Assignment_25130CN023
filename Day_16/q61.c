#include <stdio.h>

int main() {
    int n, i, expectedSum, actualSum = 0;
    int arr[100];

    printf("Enter the value of n: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n - 1);
    for (i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
        actualSum += arr[i];
    }

    expectedSum = (n * (n + 1)) / 2;

    printf("Missing number = %d\n", expectedSum - actualSum);

    return 0;
}