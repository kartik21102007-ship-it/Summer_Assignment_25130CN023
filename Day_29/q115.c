#include <stdio.h>
#include <string.h>

int main() {
    char str1[200];
    char str2[100];
    int choice;
    int len;

    printf("========================================\n");
    printf("         STRING OPERATIONS SYSTEM       \n");
    printf("========================================\n");

    printf("Enter initial string: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';

    do {
        printf("\n--- STRING OPERATIONS MENU ---\n");
        printf("1. Find Length of String\n");
        printf("2. Copy String\n");
        printf("3. Concatenate (Join) Strings\n");
        printf("4. Compare Strings\n");
        printf("5. Reverse String\n");
        printf("6. Exit\n");
        printf("Select an option (1-6): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        while (getchar() != '\n');

        switch (choice) {
            case 1:
                len = strlen(str1);
                printf("✅ Length of \"%s\" is: %d characters\n", str1, len);
                break;

            case 2:
                printf("Enter a new string to copy into the main system: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                strcpy(str1, str2);
                printf("✅ Success! Current string is now: \"%s\"\n", str1);
                break;

            case 3:
                printf("Enter string to append: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                if (strlen(str1) + strlen(str2) >= sizeof(str1)) {
                    printf("❌ Error! Combined string size exceeds allocated memory.\n");
                } else {
                    strcat(str1, str2);
                    printf("✅ Success! Joined string is: \"%s\"\n", str1);
                }
                break;

            case 4:
                printf("Enter string to compare with current string: ");
                fgets(str2, sizeof(str2), stdin);
                str2[strcspn(str2, "\n")] = '\0';
                
                int cmp = strcmp(str1, str2);
                if (cmp == 0) {
                    printf("✅ Both strings are perfectly identical.\n");
                } else if (cmp > 0) {
                    printf("ℹ️ Current string \"%s\" is lexicographically greater than \"%s\".\n", str1, str2);
                } else {
                    printf("ℹ️ Current string \"%s\" is lexicographically smaller than \"%s\".\n", str1, str2);
                }
                break;

            case 5:
                len = strlen(str1);
                for (int i = 0; i < len / 2; i++) {
                    char temp = str1[i];
                    str1[i] = str1[len - 1 - i];
                    str1[len - 1 - i] = temp;
                }
                printf("✅ Success! Reversed string is: \"%s\"\n", str1);
                break;

            case 6:
                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
