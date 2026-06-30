#include <stdio.h>

int main() {
    char str[100];
    int seen[256] = {0};
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (seen[(unsigned char)str[i]] == 0) {
            seen[(unsigned char)str[i]] = 1;
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';

    printf("String after removing duplicates: %s\n", str);

    return 0;
}