#include <stdio.h>

int convertBinaryToDecimal(long long binaryNum) {
    int decimalNum = 0;
    int base = 1;

    while (binaryNum > 0) {
        int lastDigit = binaryNum % 10;
        decimalNum += lastDigit * base;
        base = base * 2;
        binaryNum = binaryNum / 10;
    }

    return decimalNum;
}

int main() {
    long long binaryNum;

    printf("Enter a binary number: ");
    if (scanf("%lld", &binaryNum) != 1 || binaryNum < 0) {
        printf("Please enter a valid positive binary number.\n");
        return 1;
    }

    int result = convertBinaryToDecimal(binaryNum);
    printf("Decimal equivalent: %d\n", result);

    return 0;
}
