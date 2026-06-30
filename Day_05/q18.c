#include <stdio.h>

long long getFactorial(int digit) {
    long long fact = 1;
    for (int i = 1; i <= digit; i++) {
        fact *= i;
    }
    return fact;
}

int isStrongNumber(int num) {
    if (num <= 0) return 0;

    int originalNum = num;
    long long sum = 0;

    while (num > 0) {
        int digit = num % 10;
        sum += getFactorial(digit);
        num /= 10;
    }

    return (sum == originalNum);
}

int main() {
    int num;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    if (isStrongNumber(num)) {
        printf("%d is a Strong number.\n", num);
    } else {
        printf("%d is not a Strong number.\n", num);
    }

    return 0;
}
