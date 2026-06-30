#include <stdio.h>

int main() {
    int age;
    int registration_status;

    printf("========================================\n");
    printf("        VOTING ELIGIBILITY SYSTEM       \n");
    printf("========================================\n");

    printf("Enter your age: ");
    if (scanf("%d", &age) != 1 || age < 0) {
        printf("❌ Invalid age input! Please restart and enter a valid positive number.\n");
        return 1;
    }

    if (age >= 18) {
        printf("Are you registered to vote? (Enter 1 for Yes, 0 for No): ");
        if (scanf("%d", &registration_status) != 1 || (registration_status != 0 && registration_status != 1)) {
            printf("❌ Invalid selection! Please enter either 1 or 0.\n");
            return 1;
        }

        printf("----------------------------------------\n");
        if (registration_status == 1) {
            printf("✅ Status: ELIGIBLE\n");
            printf("You meet the age requirement and are successfully registered to vote.\n");
        } else {
            printf("❌ Status: NOT ELIGIBLE\n");
            printf("You are old enough, but you must register to vote first.\n");
        }
    } else {
        printf("----------------------------------------\n");
        printf("❌ Status: NOT ELIGIBLE\n");
        printf("You must be at least 18 years old to vote. You need to wait %d more year(s).\n", 18 - age);
    }
    printf("========================================\n");

    return 0;
}
