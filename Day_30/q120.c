#include <stdio.h>
#include <string.h>

void display_menu() {
    printf("\n========================================\n");
    printf("     MINI INVENTORY & BILLING SYSTEM    \n");
    printf("========================================\n");
    printf("1. Add New Item Stock\n");
    printf("2. View Current Inventory\n");
    printf("3. Generate Customer Bill\n");
    printf("4. Exit\n");
    printf("Select an option (1-4): ");
}

int add_item(int ids[], char names[][50], int quantities[], double prices[], int count) {
    if (count >= 50) {
        printf("❌ Inventory catalog full! Cannot add more items.\n");
        return count;
    }

    printf("\nEnter Item ID: ");
    if (scanf("%d", &ids[count]) != 1) {
        printf("❌ Invalid ID format!\n");
        while (getchar() != '\n');
        return count;
    }

    printf("Enter Item Name: ");
    while (getchar() != '\n');
    fgets(names[count], 50, stdin);
    names[count][strcspn(names[count], "\n")] = '\0';

    printf("Enter Stock Quantity: ");
    if (scanf("%d", &quantities[count]) != 1 || quantities[count] < 0) {
        printf("❌ Invalid quantity entered!\n");
        while (getchar() != '\n');
        return count;
    }

    printf("Enter Unit Price: $");
    if (scanf("%lf", &prices[count]) != 1 || prices[count] < 0) {
        printf("❌ Invalid price entered!\n");
        while (getchar() != '\n');
        return count;
    }

    printf("✅ Product '%s' added successfully to inventory!\n", names[count]);
    return count + 1;
}

void view_inventory(int ids[], char names[][50], int quantities[], double prices[], int count) {
    if (count == 0) {
        printf("\n📭 Inventory database is empty.\n");
        return;
    }

    printf("\n--- CURRENT STOCK CATALOG ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Item: %s | Available Qty: %d | Unit Price: $%.2f\n", 
               ids[i], names[i], quantities[i], prices[i]);
    }
}

void generate_bill(int ids[], char names[][50], int quantities[], double prices[], int count) {
    if (count == 0) {
        printf("\n📭 Billing unavailable. No items in stock.\n");
        return;
    }

    int search_id, order_qty, found = 0;
    
    printf("\nEnter Item ID to purchase: ");
    if (scanf("%d", &search_id) != 1) {
        printf("❌ Invalid ID format!\n");
        while (getchar() != '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (ids[i] == search_id) {
            found = 1;
            printf("Item Found: %s | Available Stock: %d | Price: $%.2f\n", names[i], quantities[i], prices[i]);
            printf("Enter Quantity to Buy: ");
            
            if (scanf("%d", &order_qty) != 1 || order_qty <= 0) {
                printf("❌ Invalid purchase quantity!\n");
                while (getchar() != '\n');
                return;
            }

            if (order_qty > quantities[i]) {
                printf("❌ Transaction aborted! Insufficient stock available.\n");
                return;
            }

            double total_cost = order_qty * prices[i];
            quantities[i] -= order_qty;

            printf("\n========================================\n");
            printf("             CUSTOMER RETAIL BILL       \n");
            printf("========================================\n");
            printf("Purchased Item : %s\n", names[i]);
            printf("Unit Price     : $%.2f\n", prices[i]);
            printf("Quantity       : %d\n", order_qty);
            printf("----------------------------------------\n");
            printf("TOTAL AMOUNT   : $%.2f\n", total_cost);
            printf("========================================\n");
            printf("✅ Stock level updated! Remaining units: %d\n", quantities[i]);
            return;
        }
    }

    if (!found) {
        printf("❌ Item ID %d not found in inventory catalog.\n", search_id);
    }
}

int main() {
    int item_ids[50];
    char item_names[50][50];
    int item_quantities[50];
    double item_prices[50];
    int current_count = 0;
    int choice;

    do {
        display_menu();
        if (scanf("%d", &choice) != 1) {
            printf("❌ Invalid option! Enter a valid menu selection.\n");
            while (getchar() != '\n');
            choice = 0;
            continue;
        }

        switch (choice) {
            case 1:
                current_count = add_item(item_ids, item_names, item_quantities, item_prices, current_count);
                break;
            case 2:
                view_inventory(item_ids, item_names, item_quantities, item_prices, current_count);
                break;
            case 3:
                generate_bill(item_ids, item_names, item_quantities, item_prices, current_count);
                break;
            case 4:
                printf("\nShutting down terminal. Goodbye!\n");
                break;
            default:
                printf("❌ Option outside structural index! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
