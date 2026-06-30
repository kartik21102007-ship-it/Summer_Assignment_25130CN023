#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    struct Student records[100];
    int count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("    STUDENT RECORD MANAGEMENT SYSTEM    \n");
        printf("========================================\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by ID\n");
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
                    printf("❌ Database full! Cannot add more records.\n");
                    break;
                }
                printf("\nEnter Student ID: ");
                if (scanf("%d", &records[count].id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }
                
                printf("Enter Student Name: ");
                while (getchar() != '\n');
                fgets(records[count].name, sizeof(records[count].name), stdin);
                records[count].name[strcspn(records[count].name, "\n")] = '\0';

                printf("Enter Student GPA: ");
                if (scanf("%f", &records[count].gpa) != 1 || records[count].gpa < 0.0 || records[count].gpa > 4.0) {
                    printf("❌ Invalid GPA! Must be between 0.0 and 4.0.\n");
                    while (getchar() != '\n');
                    break;
                }

                count++;
                printf("✅ Record added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No student records found.\n");
                    break;
                }
                printf("\n--- ALL STUDENT RECORDS ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | GPA: %.2f\n", records[i].id, records[i].name, records[i].gpa);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No student records available to search.\n");
                    break;
                }
                printf("\nEnter Student ID to search: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (records[i].id == search_id) {
                        printf("\n✅ Record Found:\n");
                        printf("ID: %d\nName: %s\nGPA: %.2f\n", records[i].id, records[i].name, records[i].gpa);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Student with ID %d not found.\n", search_id);
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
