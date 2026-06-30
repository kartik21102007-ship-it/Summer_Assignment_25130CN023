#include <stdio.h>
#include <string.h>

struct Contact {
    int id;
    char name[50];
    char phone[20];
    char email[50];
};

int main() {
    struct Contact directory[100];
    int count = 0;
    int next_id = 1;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("        CONTACT MANAGEMENT SYSTEM       \n");
        printf("========================================\n");
        printf("1. Add New Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact by ID\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                if (count >= 100) {
                    printf("❌ Directory full! Cannot add more contacts.\n");
                    break;
                }

                directory[count].id = next_id;

                printf("\nEnter Contact Name: ");
                while (getchar() != '\n');
                fgets(directory[count].name, sizeof(directory[count].name), stdin);
                directory[count].name[strcspn(directory[count].name, "\n")] = '\0';

                printf("Enter Phone Number: ");
                fgets(directory[count].phone, sizeof(directory[count].phone), stdin);
                directory[count].phone[strcspn(directory[count].phone, "\n")] = '\0';

                printf("Enter Email Address: ");
                fgets(directory[count].email, sizeof(directory[count].email), stdin);
                directory[count].email[strcspn(directory[count].email, "\n")] = '\0';

                printf("\n✅ Contact saved successfully! Assigned ID: %d\n", directory[count].id);
                count++;
                next_id++;
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 Your contact directory is empty.\n");
                    break;
                }
                printf("\n--- ALL CONTACTS LIST ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Phone: %s | Email: %s\n", 
                           directory[i].id, directory[i].name, directory[i].phone, directory[i].email);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No contacts available to search.\n");
                    break;
                }
                printf("\nEnter Contact ID to search: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (directory[i].id == search_id) {
                        printf("\n✅ Contact Found:\n");
                        printf("ID    : %d\nName  : %s\nPhone : %s\nEmail : %s\n", 
                               directory[i].id, directory[i].name, directory[i].phone, directory[i].email);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Contact with ID %d not found.\n", search_id);
                }
                break;

            case 4:
                printf("\nExiting system. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
