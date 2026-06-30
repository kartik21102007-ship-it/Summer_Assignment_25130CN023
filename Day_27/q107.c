#include <stdio.h>
#include <string.h>

struct SalaryRecord {
    int employee_id;
    char name[50];
    double base_salary;
    double allowances;
    double deductions;
    double net_salary;
};

int main() {
    struct SalaryRecord payroll[100];
    int count = 0;
    int choice;
    int search_id;
    int found;

    do {
        printf("\n========================================\n");
        printf("         SALARY MANAGEMENT SYSTEM       \n");
        printf("========================================\n");
        printf("1. Process Employee Salary\n");
        printf("2. Display Payroll Summary\n");
        printf("3. Generate Pay Slip by ID\n");
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
                    printf("❌ Payroll database full!\n");
                    break;
                }
                printf("\nEnter Employee ID: ");
                if (scanf("%d", &payroll[count].employee_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Employee Name: ");
                while (getchar() != '\n');
                fgets(payroll[count].name, sizeof(payroll[count].name), stdin);
                payroll[count].name[strcspn(payroll[count].name, "\n")] = '\0';

                printf("Enter Base Salary: $");
                if (scanf("%lf", &payroll[count].base_salary) != 1 || payroll[count].base_salary < 0) {
                    printf("❌ Invalid salary amount!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Allowances (Bonus, HRA, etc.): $");
                if (scanf("%lf", &payroll[count].allowances) != 1 || payroll[count].allowances < 0) {
                    printf("❌ Invalid allowance amount!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Deductions (Tax, PF, etc.): $");
                if (scanf("%lf", &payroll[count].deductions) != 1 || payroll[count].deductions < 0) {
                    printf("❌ Invalid deduction amount!\n");
                    while (getchar() != '\n');
                    break;
                }

                payroll[count].net_salary = payroll[count].base_salary + payroll[count].allowances - payroll[count].deductions;
                
                count++;
                printf("✅ Salary processed successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No payroll records found.\n");
                    break;
                }
                printf("\n--- PAYROLL SUMMARY REVENUE SYSTEM ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Net Salary: $%.2f\n", 
                           payroll[i].employee_id, payroll[i].name, payroll[i].net_salary);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No payroll records available.\n");
                    break;
                }
                printf("\nEnter Employee ID to generate pay slip: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (payroll[i].employee_id == search_id) {
                        printf("\n========================================\n");
                        printf("               PAY SLIP                 \n");
                        printf("========================================\n");
                        printf("Employee ID   : %d\n", payroll[i].employee_id);
                        printf("Name          : %s\n", payroll[i].name);
                        printf("----------------------------------------\n");
                        printf("Base Salary   : $%.2f\n", payroll[i].base_salary);
                        printf("Allowances (+) : $%.2f\n", payroll[i].allowances);
                        printf("Deductions (-) : $%.2f\n", payroll[i].deductions);
                        printf("----------------------------------------\n");
                        printf("NET SALARY    : $%.2f\n", payroll[i].net_salary);
                        printf("========================================\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Payroll records for ID %d not found.\n", search_id);
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
