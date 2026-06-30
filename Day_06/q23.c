#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    
    while (num > 0) {
        num = num & (num - 1);
        count++;
    }
    
    return count;
}

int main() {
    int num;

    printf("Enter an integer: ");
    if (scanf("%d", &num) != 1 || num < 0) {
        printf("Please enter a valid non-negative integer.\n");
        return 1;
    }

    int result = countSetBits(num);
    printf("Number of set bits: %d\n", result);

    return 0;
}
