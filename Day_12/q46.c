#include <stdio.h>

int isArmstrong(int n) {
    int original = n;
    int num = n;
    int digits = 0;
    int sum = 0;
    int remainder;
    int i, power;

    while (num != 0) {
        digits++;
        num /= 10;
    }

    num = original;

    while (num != 0) {
        remainder = num % 10;
        power = 1;
        
        for (i = 0; i < digits; i++) {
            power *= remainder;
        }
        
        sum += power;
        num /= 10;
    }

    if (sum == original) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}