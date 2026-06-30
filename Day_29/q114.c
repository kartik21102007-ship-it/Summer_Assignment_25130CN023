#include <stdio.h>

int main() {
    int arr[100];
    int size = 0;
    int choice;
    int element;
    int position;
    int found;

    do {
        printf("\n========================================\n");
        printf("      MENU-DRIVEN ARRAY OPERATIONS      \n");
        printf("========================================\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element by Position\n");
        printf("3. Search Element\n");
        printf("4. Display Array\n");
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
                if (size >= 100) {
                    printf("❌ Array capacity full! Cannot insert.\n");
                    break;
                }
                printf("Enter element to insert: ");
                if (scanf("%d", &element) != 1) {
                    printf("❌ Invalid entry!\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Enter position (0 to %d): ", size);
                if (scanf("%d", &position) != 1 || position < 0 || position > size) {
                    printf("❌ Invalid position!\n");
                    while (getchar() != '\n');
                    break;
                }

                for (int i = size; i > position; i--) {
                    arr[i] = arr[i - 1];
                }
                arr[position] = element;
                size++;
                printf("✅ Element inserted successfully!\n");
                break;

            case 2:
                if (size == 0) {
                    printf("📭 Array is empty! Nothing to delete.\n");
                    break;
                }
                printf("Enter position to delete (0 to %d): ", size - 1);
                if (scanf("%d", &position) != 1 || position < 0 || position >= size) {
                    printf("❌ Invalid position!\n");
                    while (getchar() != '\n');
                    break;
                }

                element = arr[position];
                for (int i = position; i < size - 1; i++) {
                    arr[i] = arr[i + 1];
                }
                size--;
                printf("✅ Element %d deleted successfully from position %d!\n", element, position);
                break;

            case 3:
                if (size == 0) {
                    printf("📭 Array is empty! Cannot search.\n");
                    break;
                }
                printf("Enter element to search: ");
                if (scanf("%d", &element) != 1) {
                    printf("❌ Invalid entry!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = -1;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == element) {
                        found = i;
                        break;
                    }
                }

                if (found != -1) {
                    printf("✅ Element found at index: %d\n", found);
                } else {
                    printf("❌ Element not found in the array.\n");
                }
                break;

            case 4:
                if (size == 0) {
                    printf("📭 Array is empty.\n");
                    break;
                }
                printf("\n--- CURRENT ARRAY ELEMENTS ---\n");
                printf("[");
                for (int i = 0; i < size; i++) {
                    printf("%d", arr[i]);
                    if (i < size - 1) {
                        printf(", ");
                    }
                }
                printf("]\n");
                break;

            case 5:
                printf("\nExiting array operations system. Goodbye!\n");
                break;

            default:
                printf("❌ Invalid selection! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
