#include <stdio.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    char department[30];
    double salary;
};

int main() {
    struct Employee staff[100];
    int count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("       EMPLOYEE MANAGEMENT SYSTEM       \n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
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
                    printf("❌ System full! Cannot add more employees.\n");
                    break;
                }
                printf("\nEnter Employee ID: ");
                if (scanf("%d", &staff[count].id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Employee Name: ");
                while (getchar() != '\n');
                fgets(staff[count].name, sizeof(staff[count].name), stdin);
                staff[count].name[strcspn(staff[count].name, "\n")] = '\0';

                printf("Enter Department: ");
                fgets(staff[count].department, sizeof(staff[count].department), stdin);
                staff[count].department[strcspn(staff[count].department, "\n")] = '\0';

                printf("Enter Salary: $");
                if (scanf("%lf", &staff[count].salary) != 1 || staff[count].salary < 0) {
                    printf("❌ Invalid salary amount!\n");
                    while (getchar() != '\n');
                    break;
                }

                count++;
                printf("✅ Employee added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No employee records found.\n");
                    break;
                }
                printf("\n--- ALL EMPLOYEE RECORDS ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Dept: %s | Salary: $%.2f\n", 
                           staff[i].id, staff[i].name, staff[i].department, staff[i].salary);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No records available to search.\n");
                    break;
                }
                printf("\nEnter Employee ID to search: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (staff[i].id == search_id) {
                        printf("\n✅ Employee Found:\n");
                        printf("ID: %d\nName: %s\nDept: %s\nSalary: $%.2f\n", 
                               staff[i].id, staff[i].name, staff[i].department, staff[i].salary);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Employee with ID %d not found.\n", search_id);
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
