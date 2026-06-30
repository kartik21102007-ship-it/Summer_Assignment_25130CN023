#include <stdio.h>

int main() {
    int n, i;
    int evenCount = 0, oddCount = 0;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    printf("Total even elements: %d\n", evenCount);
    printf("Total odd elements: %d\n", oddCount);

    return 0;
}