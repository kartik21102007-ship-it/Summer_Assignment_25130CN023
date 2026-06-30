#include <stdio.h>

int main() {
    char str[200];
    int freq[256] = {0};
    int i = 0, max_freq = 0;
    char max_char;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        freq[(unsigned char)str[i]]++;
        i++;
    }

    for (i = 0; i < 256; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            max_char = i;
        }
    }

    printf("Maximum occurring character is '%c' = %d times.\n", max_char, max_freq);

    return 0;
}