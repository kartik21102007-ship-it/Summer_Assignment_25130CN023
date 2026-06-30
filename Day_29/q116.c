#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    int quantity;
    double price;
};

int main() {
    struct Product inventory[100];
    int count = 0;
    int choice;
    int search_id;
    int update_qty;
    int found;

    do {
        printf("\n========================================\n");
        printf("       INVENTORY MANAGEMENT SYSTEM      \n");
        printf("========================================\n");
        printf("1. Add New Product\n");
        printf("2. Display Current Stock\n");
        printf("3. Update Product Quantity\n");
        printf("4. Search Product by ID\n");
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
                    printf("❌ Inventory capacity full! Cannot add items.\n");
                    break;
                }
                printf("\nEnter Product ID: ");
                if (scanf("%d", &inventory[count].id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Product Name: ");
                while (getchar() != '\n');
                fgets(inventory[count].name, sizeof(inventory[count].name), stdin);
                inventory[count].name[strcspn(inventory[count].name, "\n")] = '\0';

                printf("Enter Initial Quantity: ");
                if (scanf("%d", &inventory[count].quantity) != 1 || inventory[count].quantity < 0) {
                    printf("❌ Invalid stock count!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Unit Price: $");
                if (scanf("%lf", &inventory[count].price) != 1 || inventory[count].price < 0) {
                    printf("❌ Invalid price amount!\n");
                    while (getchar() != '\n');
                    break;
                }

                count++;
                printf("✅ Product successfully logged in inventory!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 The warehouse inventory is completely empty.\n");
                    break;
                }
                printf("\n--- CURRENT WAREHOUSE STOCK ---\n");
                for (int i = 0; i < count; i++) {
                    printf("ID: %d | Name: %s | Qty: %d | Price: $%.2f | Total Value: $%.2f\n", 
                           inventory[i].id, inventory[i].name, inventory[i].quantity, 
                           inventory[i].price, inventory[i].quantity * inventory[i].price);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No products available to update.\n");
                    break;
                }
                printf("\nEnter Product ID to adjust stock level: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == search_id) {
                        found = 1;
                        printf("Current stock for '%s' is %d. Enter new total quantity: ", inventory[i].name, inventory[i].quantity);
                        if (scanf("%d", &update_qty) != 1 || update_qty < 0) {
                            printf("❌ Invalid item count! Transaction aborted.\n");
                            while (getchar() != '\n');
                        } else {
                            inventory[i].quantity = update_qty;
                            printf("✅ Stock level updated! New count: %d\n", inventory[i].quantity);
                        }
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Product code %d not found in database.\n", search_id);
                }
                break;

            case 4:
                if (count == 0) {
                    printf("\n📭 No product items registered to look up.\n");
                    break;
                }
                printf("\nEnter Product ID to search: ");
                if (scanf("%d", &search_id) != 1) {
                    printf("❌ Invalid ID format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == search_id) {
                        printf("\n📦 SKU Match Found:\n");
                        printf("ID         : %d\nName       : %s\nStock Count: %d units\nUnit Price : $%.2f\n", 
                               inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Item reference %d not tracked in catalog.\n", search_id);
                }
                break;

            case 5:
                printf("\nExiting system terminal. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
