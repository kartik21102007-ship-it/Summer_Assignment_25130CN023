#include <stdio.h>
#include <stdlib.h> 
int is_palindrome(int number) {
    int original = abs(number);
    int reversed = 0;
    int temp = original;
    while (temp > 0) {
        int digit = temp % 10;
        if (reversed > (2147483647 - digit) / 10) {
            return 0;
        }   
        reversed = (reversed * 10) + digit;
        temp = temp / 10;
    }
    return (original == reversed);
}
int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    if (is_palindrome(num)) {
        printf("%d is a palindrome number.\n", num);
    } else {
        printf("%d is not a palindrome number.\n", num);
    }   
    return 0;
}