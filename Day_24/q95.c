#include <stdio.h>

int main() {
    char str[200], longest[200];
    int i = 0, j = 0, max_len = 0, current_len = 0;
    int max_start = 0, current_start = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            if (current_len == 0) {
                current_start = i;
            }
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                max_start = current_start;
            }
            current_len = 0;
        }
        i++;
    }

    if (current_len > max_len) {
        max_len = current_len;
        max_start = current_start;
    }

    for (j = 0; j < max_len; j++) {
        longest[j] = str[max_start + j];
    }
    longest[max_len] = '\0';

    printf("Longest word: %s\n", longest);
    printf("Length: %d\n", max_len);

    return 0;
}