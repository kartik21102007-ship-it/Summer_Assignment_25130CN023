#include <stdio.h>
#include <string.h>

struct BankAccount {
    int account_number;
    char holder_name[50];
    double balance;
};

int main() {
    struct BankAccount accounts[100];
    int count = 0;
    int choice;
    int search_acc;
    int found;
    double amount;

    do {
        printf("\n========================================\n");
        printf("          BANK ACCOUNT SYSTEM           \n");
        printf("========================================\n");
        printf("1. Create New Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account Details\n");
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
                    printf("❌ Database full! Cannot open more accounts.\n");
                    break;
                }
                printf("\nEnter Account Number: ");
                if (scanf("%d", &accounts[count].account_number) != 1) {
                    printf("❌ Invalid account number format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Account Holder Name: ");
                while (getchar() != '\n');
                fgets(accounts[count].holder_name, sizeof(accounts[count].holder_name), stdin);
                accounts[count].holder_name[strcspn(accounts[count].holder_name, "\n")] = '\0';

                printf("Enter Initial Deposit Amount: $");
                if (scanf("%lf", &accounts[count].balance) != 1 || accounts[count].balance < 0) {
                    printf("❌ Invalid amount! Opening balance cannot be negative.\n");
                    while (getchar() != '\n');
                    break;
                }

                count++;
                printf("✅ Account created successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No accounts registered in the system.\n");
                    break;
                }
                printf("\nEnter Account Number for deposit: ");
                if (scanf("%d", &search_acc) != 1) {
                    printf("❌ Invalid format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (accounts[i].account_number == search_acc) {
                        found = 1;
                        printf("Enter deposit amount: $");
                        if (scanf("%lf", &amount) != 1 || amount <= 0) {
                            printf("❌ Invalid amount. Transaction cancelled.\n");
                            while (getchar() != '\n');
                        } else {
                            accounts[i].balance += amount;
                            printf("✅ Success! Deposited $%.2f. New Balance: $%.2f\n", amount, accounts[i].balance);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Account number %d not found.\n", search_acc);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No accounts registered in the system.\n");
                    break;
                }
                printf("\nEnter Account Number for withdrawal: ");
                if (scanf("%d", &search_acc) != 1) {
                    printf("❌ Invalid format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (accounts[i].account_number == search_acc) {
                        found = 1;
                        printf("Enter withdrawal amount: $");
                        if (scanf("%lf", &amount) != 1 || amount <= 0) {
                            printf("❌ Invalid amount. Transaction cancelled.\n");
                            while (getchar() != '\n');
                        } else if (amount > accounts[i].balance) {
                            printf("❌ Insufficient funds! Current Balance: $%.2f\n", accounts[i].balance);
                        } else {
                            accounts[i].balance -= amount;
                            printf("✅ Success! Withdrew $%.2f. New Balance: $%.2f\n", amount, accounts[i].balance);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Account number %d not found.\n", search_acc);
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\n📭 No accounts registered in the system.\n");
                    break;
                }
                printf("\nEnter Account Number to display details: ");
                if (scanf("%d", &search_acc) != 1) {
                    printf("❌ Invalid format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (accounts[i].account_number == search_acc) {
                        printf("\n--- ACCOUNT DETAILS ---\n");
                        printf("Account Number: %d\n", accounts[i].account_number);
                        printf("Holder Name   : %s\n", accounts[i].holder_name);
                        printf("Current Balance: $%.2f\n", accounts[i].balance);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Account number %d not found.\n", search_acc);
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
