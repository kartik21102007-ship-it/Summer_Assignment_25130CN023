#include <stdio.h>
#include <string.h>

int main() {
    int emp_ids[50];
    char emp_names[50][50];
    double emp_salaries[50];
    int emp_count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("       MINI EMPLOYEE MANAGEMENT         \n");
        printf("========================================\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee by ID\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                if (emp_count >= 50) {
                    printf("❌ Roster capacity reached!\n");
                    break;
                }

                printf("\nEnter Employee ID number: ");
                if (scanf("%d", &emp_ids[emp_count]) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Employee Name: ");
                while (getchar() != '\n');
                fgets(emp_names[emp_count], sizeof(emp_names[emp_count]), stdin);
                emp_names[emp_count][strcspn(emp_names[emp_count], "\n")] = '\0';

                printf("Enter Salary: $");
                if (scanf("%lf", &emp_salaries[emp_count]) != 1 || emp_salaries[emp_count] < 0) {
                    printf("❌ Invalid salary amount!\n");
                    while (getchar() != '\n');
                    break;
                }

                emp_count++;
                printf("✅ Employee recorded successfully!\n");
                break;

            case 2:
                if (emp_count == 0) {
                    printf("\n📭 No employees registered yet.\n");
                    break;
                }
                printf("\n--- EMPLOYEE ROSTER LIST ---\n");
                for (int i = 0; i < emp_count; i++) {
                    printf("ID: %d | Name: %s | Salary: $%.2f\n", 
                           emp_ids[i], emp_names[i], emp_salaries[i]);
                }
                break;

            case 3:
                if (emp_count == 0) {
                    printf("\n📭 No data tracked to search.\n");
                    break;
                }
                printf("\nEnter Employee ID to search: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < emp_count; i++) {
                    if (emp_ids[i] == search_id) {
                        found = 1;
                        printf("\n✅ Match Discovered:\n");
                        printf("ID    : %d\nName  : %s\nSalary: $%.2f\n", 
                               emp_ids[i], emp_names[i], emp_salaries[i]);
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Employee ID %d not found.\n", search_id);
                }
                break;

            case 4:
                printf("\nClosing employee app. Goodbye!\n");
                break;

            default:
                printf("❌ Selection choice out of index! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
