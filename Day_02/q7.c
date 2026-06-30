#include <stdio.h>
#include <stdlib.h> 
int get_product_of_digits(int number) {
    number = abs(number);
    if (number == 0) {
        return 0;
    }
    int product = 1;
    while (number > 0) {
        int digit = number % 10;   
        product *= digit;        
        number = number / 10;      
    }   
    return product;
}
int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input.\n");
        return 1;
    }
    int result = get_product_of_digits(num);
    printf("The product of the digits of %d is: %d\n", num, result);   
    return 0;
}