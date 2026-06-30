#include <stdio.h>
#include <string.h>

struct Book {
    int id;
    char title[100];
    char author[50];
    int is_issued;
};

int main() {
    struct Book library[100];
    int count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("       LIBRARY MANAGEMENT SYSTEM        \n");
        printf("========================================\n");
        printf("1. Add New Book\n");
        printf("2. Display All Books\n");
        printf("3. Issue a Book\n");
        printf("4. Return a Book\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= 100) {
                    printf("❌ Library database full!\n");
                    break;
                }
                printf("\nEnter Book ID: ");
                if (scanf("%d", &library[count].id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Book Title: ");
                while (getchar() != '\n');
                fgets(library[count].title, sizeof(library[count].title), stdin);
                library[count].title[strcspn(library[count].title, "\n")] = '\0';

                printf("Enter Author Name: ");
                fgets(library[count].author, sizeof(library[count].author), stdin);
                library[count].author[strcspn(library[count].author, "\n")] = '\0';

                library[count].is_issued = 0;
                count++;
                printf("✅ Book added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No books available in the library.\n");
                    break;
                }
                printf("\n--- LIBRARY BOOKS CATALOG ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Title: %s | Author: %s | Status: %s\n", 
                           library[i].id, library[i].title, library[i].author, 
                           library[i].is_issued ? "Issued 🛑" : "Available ✅");
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No books registered to issue.\n");
                    break;
                }
                printf("\nEnter Book ID to issue: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (library[i].id == search_id) {
                        found = 1;
                        if (library[i].is_issued == 1) {
                            printf("❌ Book is already issued to someone else.\n");
                        } else {
                            library[i].is_issued = 1;
                            printf("✅ Success! Book '%s' has been issued.\n", library[i].title);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Book with ID %d not found.\n", search_id);
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\n📭 No books registered to return.\n");
                    break;
                }
                printf("\nEnter Book ID to return: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (library[i].id == search_id) {
                        found = 1;
                        if (library[i].is_issued == 0) {
                            printf("❌ Book is already available in the library.\n");
                        } else {
                            library[i].is_issued = 0;
                            printf("✅ Success! Book '%s' has been returned.\n", library[i].title);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Book with ID %d not found.\n", search_id);
                }
                break;

            case 5:
                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
