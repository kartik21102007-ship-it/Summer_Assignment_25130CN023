#include <stdio.h>

int main() {
    int n1, n2, i = 0, j = 0, k = 0, x;
    int arr1[100], arr2[100], merged[200];

    printf("Enter the size of the first sorted array: ");
    scanf("%d", &n1);
    printf("Enter elements of the first array:\n");
    for (x = 0; x < n1; x++) {
        scanf("%d", &arr1[x]);
    }

    printf("Enter the size of the second sorted array: ");
    scanf("%d", &n2);
    printf("Enter elements of the second array:\n");
    for (x = 0; x < n2; x++) {
        scanf("%d", &arr2[x]);
    }

    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < n2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    printf("Merged sorted array is:\n");
    for (x = 0; x < n1 + n2; x++) {
        printf("%d ", merged[x]);
    }
    printf("\n");

    return 0;
}