#include <stdio.h>

int main() {
    char str[200];
    int i = 0, count = 0, inWord = 0;

    printf("Enter a sentence: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t') {
            inWord = 0;
        } else if (inWord == 0) {
            inWord = 1;
            count++;
        }
        i++;
    }

    printf("Number of words: %d\n", count);

    return 0;
}