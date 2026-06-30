#include <stdio.h>
#include <math.h>
int is_prime_year(int year) {
    if (year <= 1) {
        return 0;
    }
    if (year == 2) {
        return 1;
    }
    if (year % 2 == 0) {
        return 0;
    }
    int limit = (int)sqrt(year);
    for (int i = 3; i <= limit; i += 2) {
        if (year % i == 0) {
            return 0; 
        }
    }
    return 1;
}
int main() {
    int year;
    printf("Enter a year to check: ");
    if (scanf("%d", &year) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1;
    }
    if (is_prime_year(year)) {
        printf("Yes, %d is a prime year!\n", year);
    } else {
        printf("No, %d is not a prime year.\n", year);
    }
    return 0;
}