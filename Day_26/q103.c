#include <stdio.h>

int main() {
    double balance = 1000.00;
    int pin = 1234;
    int entered_pin;
    int pin_attempts = 0;
    int choice;
    double amount;

    printf("========================================\n");
    printf("          WELCOME TO THE ATM            \n");
    printf("========================================\n");

    while (pin_attempts < 3) {
        printf("Enter your 4-digit PIN: ");
        if (scanf("%d", &entered_pin) != 1) {
            printf("❌ Invalid characters entered.\n\n");
            while (getchar() != '\n');
            pin_attempts++;
            continue;
        }

        if (entered_pin == pin) {
            break;
        } else {
            pin_attempts++;
            printf("❌ Incorrect PIN. Remaining attempts: %d\n\n", 3 - pin_attempts);
        }
    }

    if (pin_attempts == 3) {
        printf("========================================\n");
        printf("🔒 Card blocked! Too many incorrect PIN attempts.\n");
        printf("========================================\n");
        return 1;
    }

    do {
        printf("\n--- ATM MAIN MENU ---\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Select an option (1-4): ");
        
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option. Please enter a number between 1 and 4.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                printf("\n💳 Current Balance: $%.2f\n", balance);
                break;

            case 2:
                printf("\nEnter deposit amount: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("❌ Invalid amount. Transaction cancelled.\n");
                    while (getchar() != '\n');
                } else {
                    balance += amount;
                    printf("✅ Success! New Balance: $%.2f\n", balance);
                }
                break;

            case 3:
                printf("\nEnter withdrawal amount: $");
                if (scanf("%lf", &amount) != 1 || amount <= 0) {
                    printf("❌ Invalid amount. Transaction cancelled.\n");
                    while (getchar() != '\n');
                } else if (amount > balance) {
                    printf("❌ Insufficient funds! Current Balance: $%.2f\n", balance);
                } else {
                    balance -= amount;
                    printf("✅ Success! Please collect your cash.\n");
                    printf("New Balance: $%.2f\n", balance);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    printf("========================================\n");
    return 0;
}
