#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int present1[256] = {0};
    int present2[256] = {0};
    int i = 0, found = 0;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    while (str1[i] != '\0') {
        present1[(unsigned char)str1[i]] = 1;
        i++;
    }

    i = 0;
    while (str2[i] != '\0') {
        present2[(unsigned char)str2[i]] = 1;
        i++;
    }

    printf("Common characters: ");
    for (i = 0; i < 256; i++) {
        if (present1[i] == 1 && present2[i] == 1) {
            printf("%c ", i);
            found = 1;
        }
    }

    if (!found) {
        printf("None");
    }
    printf("\n");

    return 0;
}