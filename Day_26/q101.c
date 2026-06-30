#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int lower_bound = 1;
    int upper_bound = 100;
    int max_attempts = 7;
    int secret_number;
    int guess;
    int attempts = 0;
    int input_status;

    srand(time(NULL));
    secret_number = (rand() % (upper_bound - lower_bound + 1)) + lower_bound;

    printf("========================================\n");
    printf("     WELCOME TO THE NUMBER GUESSING GAME!     \n");
    printf("========================================\n");
    printf("I am thinking of a number between %d and %d.\n", lower_bound, upper_bound);
    printf("You have exactly %d attempts to guess it.\n\n", max_attempts);

    while (attempts < max_attempts) {
        printf("Attempt %d/%d | Enter your guess: ", attempts + 1, max_attempts);
        input_status = scanf("%d", &guess);

        if (input_status != 1) {
            printf("❌ Invalid input! Please enter a valid whole number.\n\n");
            while (getchar() != '\n');
            continue;
        }

        if (guess < lower_bound || guess > upper_bound) {
            printf("⚠ Out of bounds! Please guess a number from %d to %d.\n\n", lower_bound, upper_bound);
            continue;
        }

        attempts++;

        if (guess == secret_number) {
            printf("\n🎉 Congratulations! You guessed the correct number (%d) in %d attempts!\n", secret_number, attempts);
            return 0;
        } else if (guess < secret_number) {
            printf("📉 Too low! Try a higher number.\n\n");
        } else {
            printf("📈 Too high! Try a lower number.\n\n");
        }
    }

    printf("========================================\n");
    printf("💀 Game Over! You've run out of attempts.\n");
    printf("The correct number was: %d\n", secret_number);
    printf("========================================\n");

    return 0;
}
