#include <stdio.h>

int main() {
    int n1, n2, i, j, k, isDuplicate;
    int arr1[100], arr2[100];

    printf("Enter the number of elements for first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the number of elements for second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }

    printf("Intersection of arrays:\n");
    for (i = 0; i < n1; i++) {
        isDuplicate = 0;
        
        for (k = 0; k < i; k++) {
            if (arr1[i] == arr1[k]) {
                isDuplicate = 1;
                break;
            }
        }
        
        if (!isDuplicate) {
            for (j = 0; j < n2; j++) {
                if (arr1[i] == arr2[j]) {
                    printf("%d ", arr1[i]);
                    break;
                }
            }
        }
    }
    printf("\n");

    return 0;
}