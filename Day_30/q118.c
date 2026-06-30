#include <stdio.h>
#include <string.h>

int main() {
    int book_ids[50];
    char book_titles[50][100];
    int is_borrowed[50] = {0};
    int book_count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("          MINI LIBRARY SYSTEM           \n");
        printf("========================================\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                if (book_count >= 50) {
                    printf("❌ Library capacity reached!\n");
                    break;
                }

                printf("\nEnter Book ID number: ");
                if (scanf("%d", &book_ids[book_count]) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Book Title: ");
                while (getchar() != '\n');
                fgets(book_titles[book_count], sizeof(book_titles[book_count]), stdin);
                book_titles[book_count][strcspn(book_titles[book_count], "\n")] = '\0';

                is_borrowed[book_count] = 0;
                book_count++;
                printf("✅ Book stored successfully!\n");
                break;

            case 2:
                if (book_count == 0) {
                    printf("\n📭 No books registered yet.\n");
                    break;
                }
                printf("\n--- CATALOG LIST ---\n");
                for (int i = 0; i < book_count; i++) {
                    printf("ID: %d | Title: %s | Status: %s\n", 
                           book_ids[i], book_titles[i], 
                           is_borrowed[i] ? "Borrowed 🛑" : "Available ✅");
                }
                break;

            case 3:
                if (book_count == 0) {
                    printf("\n📭 No books available to borrow.\n");
                    break;
                }
                printf("\nEnter Book ID to borrow: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < book_count; i++) {
                    if (book_ids[i] == search_id) {
                        found = 1;
                        if (is_borrowed[i] == 1) {
                            printf("❌ Book is currently checked out.\n");
                        } else {
                            is_borrowed[i] = 1;
                            printf("✅ Success! You checked out \"%s\".\n", book_titles[i]);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Book ID %d not found.\n", search_id);
                }
                break;

            case 4:
                if (book_count == 0) {
                    printf("\n📭 No books tracked to return.\n");
                    break;
                }
                printf("\nEnter Book ID to return: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < book_count; i++) {
                    if (book_ids[i] == search_id) {
                        found = 1;
                        if (is_borrowed[i] == 0) {
                            printf("❌ This book is already on the shelf.\n");
                        } else {
                            is_borrowed[i] = 0;
                            printf("✅ Success! \"%s\" has been returned.\n", book_titles[i]);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Book ID %d not found.\n", search_id);
                }
                break;

            case 5:
                printf("\nClosing mini library app. Goodbye!\n");
                break;

            default:
                printf("❌ Selection choice out of index! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
