#include <stdio.h>
#include <string.h>

int main() {
    char str[500], words[100][100], temp[100];
    int i = 0, j = 0, k = 0, num_words = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t') {
            words[j][k++] = str[i];
        } else {
            if (k > 0) { 
                words[j][k] = '\0';
                j++;
                k = 0;
            }
        }
        i++;
    }
    
    if (k > 0) {
        words[j][k] = '\0';
        num_words = j + 1;
    } else {
        num_words = j;
    }

    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strlen(words[i]) > strlen(words[j])) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    printf("\nWords sorted by length:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }

    return 0;
}