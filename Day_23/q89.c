#include <stdio.h>

int main() {
    char str[100];
    int freq[256] = {0};
    int i = 0, found = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    i = 0;
    while (str[i] != '\0') {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            found = 1;
            break;
        }
        i++;
    }

    if (!found) {
        printf("No non-repeating character found.\n");
    }

    return 0;
}