#include <stdio.h>

double power(double x, int n) {
    double result = 1.0;
    long long absN = n;

    if (absN < 0) {
        absN = -absN;
    }

    while (absN > 0) {
        if (absN % 2 == 1) {
            result *= x;
        }
        x *= x;
        absN /= 2;
    }

    if (n < 0) {
        return 1.0 / result;
    }
    
    return result;
}

int main() {
    double x;
    int n;

    printf("Enter base (x): ");
    if (scanf("%lf", &x) != 1) return 1;

    printf("Enter exponent (n): ");
    if (scanf("%d", &n) != 1) return 1;

    double result = power(x, n);
    printf("%.6f^%d = %.6f\n", x, n, result);

    return 0;
}
