#include <stdio.h>
#include <string.h>

int main() {
    int ids[100];
    char names[100][50];
    char courses[100][30];
    int count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("    STUDENT RECORD SYSTEM (ARRAY/STR)   \n");
        printf("========================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Student Records\n");
        printf("3. Search Student Record by ID\n");
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
                    printf("❌ System full! Cannot store more student data.\n");
                    break;
                }

                printf("\nEnter Student ID: ");
                if (scanf("%d", &ids[count]) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Student Name: ");
                while (getchar() != '\n');
                fgets(names[count], sizeof(names[count]), stdin);
                names[count][strcspn(names[count], "\n")] = '\0';

                printf("Enter Course Name: ");
                fgets(courses[count], sizeof(courses[count]), stdin);
                courses[count][strcspn(courses[count], "\n")] = '\0';

                count++;
                printf("✅ Student profile recorded successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 Database index is empty. No logs found.\n");
                    break;
                }
                printf("\n--- COMPLETE STUDENT DIRECTORY ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Course: %s\n", ids[i], names[i], courses[i]);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No data strings logged to search.\n");
                    break;
                }
                printf("\nEnter Student ID to query: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (ids[i] == search_id) {
                        printf("\n✅ Match Discovered:\n");
                        printf("ID    : %d\nName  : %s\nCourse: %s\n", ids[i], names[i], courses[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Record lookup failed for ID %d.\n", search_id);
                }
                break;

            case 4:
                printf("\nShutting down register system. Goodbye!\n");
                break;

            default:
                printf("❌ Selection out of index array! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
