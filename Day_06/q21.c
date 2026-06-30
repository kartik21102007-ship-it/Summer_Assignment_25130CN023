#include <stdio.h>

void convertDecimalToBinary(int num) {
    if (num == 0) {
        printf("Binary equivalent: 0\n");
        return;
    }

    int binaryArray[32];
    int i = 0;

    while (num > 0) {
        binaryArray[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary equivalent: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryArray[j]);
    }
    printf("\n");
}

int main() {
    int num;

    printf("Enter a decimal number: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    convertDecimalToBinary(num);
    return 0;
}
