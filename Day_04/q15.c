#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    int originalNum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;

    if (num < 0) return 0;

    while (temp > 0) {
        digits++;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        int remainder = temp % 10;
        sum += round(pow(remainder, digits));
        temp /= 10;
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

    if (isArmstrong(num)) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }

    return 0;
}
