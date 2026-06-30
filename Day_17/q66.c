#include <stdio.h>

int main() {
    int n1, n2, i, j, k = 0, isDuplicate;
    int arr1[100], arr2[100], unionArr[200];

    printf("Enter the number of elements for first array: ");
    scanf("%d", &n1);

    printf("Enter %d elements:\n", n1);
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
        isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr1[i] == unionArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k++] = arr1[i];
        }
    }

    printf("Enter the number of elements for second array: ");
    scanf("%d", &n2);

    printf("Enter %d elements:\n", n2);
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
        isDuplicate = 0;
        for (j = 0; j < k; j++) {
            if (arr2[i] == unionArr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unionArr[k++] = arr2[i];
        }
    }

    printf("Union of arrays:\n");
    for (i = 0; i < k; i++) {
        printf("%d ", unionArr[i]);
    }
    printf("\n");

    return 0;
}