#include <stdio.h>

int main() {
    char str1[100], str2[100], temp[200];
    int len1 = 0, len2 = 0, i, k, found = 0, match;

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    while (str1[len1] != '\0') {
        len1++;
    }
    
    while (str2[len2] != '\0') {
        len2++;
    }

    if (len1 != len2 || len1 == 0) {
        printf("The strings are not rotations of each other.\n");
        return 0;
    }

    for (i = 0; i < len1; i++) {
        temp[i] = str1[i];
        temp[i + len1] = str1[i];
    }
    temp[len1 * 2] = '\0';

    for (i = 0; i <= (len1 * 2) - len2; i++) {
        match = 1;
        for (k = 0; k < len2; k++) {
            if (temp[i + k] != str2[k]) {
                match = 0;
                break;
            }
        }
        if (match) {
            found = 1;
            break;
        }
    }

    if (found) {
        printf("The strings are rotations of each other.\n");
    } else {
        printf("The strings are not rotations of each other.\n");
    }

    return 0;
}