#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int max, second_max;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (arr[0] > arr[1]) {
        max = arr[0];
        second_max = arr[1];
    } else {
        max = arr[1];
        second_max = arr[0];
    }

    for (i = 2; i < n; i++) {
        if (arr[i] > max) {
            second_max = max;
            max = arr[i];
        } else if (arr[i] > second_max && arr[i] != max) {
            second_max = arr[i];
        }
    }

    printf("Second largest element = %d\n", second_max);

    return 0;
}