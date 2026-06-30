#include <stdio.h>

int main() {
    char str[200];
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';

    printf("String after removing spaces: %s\n", str);

    return 0;
}