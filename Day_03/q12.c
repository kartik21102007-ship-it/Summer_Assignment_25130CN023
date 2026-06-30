#include <stdio.h>
int find_gcd(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
int main() {
    int num1, num2;
    printf("Enter first number: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    printf("Enter second number: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int abs_num1 = (num1 < 0) ? -num1 : num1;
    int abs_num2 = (num2 < 0) ? -num2 : num2;
    if (abs_num1 == 0 || abs_num2 == 0) {
        printf("The LCM of %d and %d is: 0\n", num1, num2);
        return 0;
    }
    int gcd = find_gcd(abs_num1, abs_num2);
    int lcm = (abs_num1 / gcd) * abs_num2;
    printf("The LCM of %d and %d is: %d\n", num1, num2, lcm);
    return 0;
}