#include <stdio.h>

int main() {
    int choice;
    double num1, num2, result;

    do {
        printf("\n========================================\n");
        printf("         MENU-DRIVEN CALCULATOR         \n");
        printf("========================================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");

        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Please enter a number.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        if (choice >= 1 && choice <= 4) {
            printf("Enter first number: ");
            if (scanf("%lf", &num1) != 1) {
                printf("❌ Invalid number input!\n");
                while (getchar() != '\n');
                continue;
            }

            printf("Enter second number: ");
            if (scanf("%lf", &num2) != 1) {
                printf("❌ Invalid number input!\n");
                while (getchar() != '\n');
                continue;
            }
        }

        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("✅ Result: %.2lf + %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 2:
                result = num1 - num2;
                printf("✅ Result: %.2lf - %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 3:
                result = num1 * num2;
                printf("✅ Result: %.2lf * %.2lf = %.2lf\n", num1, num2, result);
                break;

            case 4:
                if (num2 == 0) {
                    printf("❌ Error! Division by zero is not allowed.\n");
                } else {
                    result = num1 / num2;
                    printf("✅ Result: %.2lf / %.2lf = %.2lf\n", num1, num2, result);
                }
                break;

            case 5:
                printf("\nExiting calculator. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Please choose a valid operation.\n");
        }
    } while (choice != 5);

    return 0;
}
