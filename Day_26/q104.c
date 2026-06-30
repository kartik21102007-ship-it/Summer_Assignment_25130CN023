#include <stdio.h>
#include <ctype.h>

int main() {
    char answers[3] = {'C', 'B', 'A'};
    char user_guess;
    int score = 0;

    printf("========================================\n");
    printf("           QUIZ APPLICATION             \n");
    printf("========================================\n\n");

    printf("Question 1: Which programming language is known as the 'mother of all languages'?\n");
    printf("A. Python\n");
    printf("B. Java\n");
    printf("C. C\n");
    printf("D. C++\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &user_guess);
    user_guess = toupper(user_guess);
    if (user_guess == answers[0]) {
        printf("✅ Correct!\n\n");
        score++;
    } else {
        printf("❌ Incorrect! The right answer is C.\n\n");
    }

    printf("Question 2: What is the size of an 'int' data type in C on most 32-bit/64-bit systems?\n");
    printf("A. 2 bytes\n");
    printf("B. 4 bytes\n");
    printf("C. 8 bytes\n");
    printf("D. 1 byte\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &user_guess);
    user_guess = toupper(user_guess);
    if (user_guess == answers[1]) {
        printf("✅ Correct!\n\n");
        score++;
    } else {
        printf("❌ Incorrect! The right answer is B.\n\n");
    }

    printf("Question 3: Which keyword is used to prevent any changes to a variable in C?\n");
    printf("A. const\n");
    printf("B. static\n");
    printf("C. volatile\n");
    printf("D. immutable\n");
    printf("Your answer (A/B/C/D): ");
    scanf(" %c", &user_guess);
    user_guess = toupper(user_guess);
    if (user_guess == answers[2]) {
        printf("✅ Correct!\n\n");
        score++;
    } else {
        printf("❌ Incorrect! The right answer is A.\n\n");
    }

    printf("========================================\n");
    printf("             QUIZ RESULTS               \n");
    printf("========================================\n");
    printf("Your Final Score: %d out of 3\n", score);
    printf("Percentage: %.1f%%\n", (score / 3.0) * 100);
    printf("========================================\n");

    return 0;
}
