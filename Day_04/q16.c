#include <stdio.h>
#include <math.h>

int isArmstrong(int num) {
    if (num < 0) return 0;
    
    int originalNum = num;
    int temp = num;
    int digits = 0;
    int sum = 0;

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
    int start, end;

    printf("Enter lower limit: ");
    if (scanf("%d", &start) != 1) return 1;

    printf("Enter upper limit: ");
    if (scanf("%d", &end) != 1) return 1;

    printf("Armstrong numbers between %d and %d are:\n", start, end);
    for (int i = start; i <= end; i++) {
        if (isArmstrong(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
