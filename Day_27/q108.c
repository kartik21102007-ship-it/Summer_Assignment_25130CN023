#include <stdio.h>
#include <string.h>

struct Marksheet {
    int roll_number;
    char student_name;
    int marks;
    int total_marks;
    float percentage;
    char grade;
};

int main() {
    struct Marksheet students;
    int count = 0;
    int choice;
    int search_roll;
    int found;

    do {
        printf("\n========================================\n");
        printf("       MARKSHEET GENERATION SYSTEM      \n");
        printf("========================================\n");
        printf("1. Input Student Marks\n");
        printf("2. Display All Student Percentages\n");
        printf("3. Generate Marksheet by Roll No\n");
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
                    printf("❌ Database full!\n");
                    break;
                }
                printf("\nEnter Roll Number: ");
                if (scanf("%d", &students[count].roll_number) != 1) {
                    printf("❌ Invalid Roll Number format!\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter Student Name: ");
                while (getchar() != '\n');
                fgets(students[count].student_name, sizeof(students[count].student_name), stdin);
                students[count].student_name[strcspn(students[count].student_name, "\n")] = '\0';

                students[count].total_marks = 0;
                int invalid_mark = 0;

                char subjects = {"Mathematics", "Physics", "Chemistry"};
                for (int i = 0; i < 3; i++) {
                    printf("Enter marks for %s (0-100): ", subjects[i]);
                    if (scanf("%d", &students[count].marks[i]) != 1 || students[count].marks[i] < 0 || students[count].marks[i] > 100) {
                        printf("❌ Invalid marks! Must be between 0 and 100.\n");
                        while (getchar() != '\n');
                        invalid_mark = 1;
                        break;
                    }
                    students[count].total_marks += students[count].marks[i];
                }

                if (invalid_mark) {
                    break;
                }

                students[count].percentage = (students[count].total_marks / 300.0) * 100;

                if (students[count].percentage >= 90) {
                    students[count].grade = 'A';
                } else if (students[count].percentage >= 75) {
                    students[count].grade = 'B';
                } else if (students[count].percentage >= 50) {
                    students[count].grade = 'C';
                } else if (students[count].percentage >= 35) {
                    students[count].grade = 'D';
                } else {
                    students[count].grade = 'F';
                }

                count++;
                printf("✅ Marks recorded successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("\n📭 No student marks found.\n");
                    break;
                }
                printf("\n--- STUDENT PERCENTAGE SUMMARY ---\n");
                for (int i = 0; i < count; i++) {
                    printf("Roll No: %d | Name: %s | Percentage: %.2f%%\n", 
                           students[i].roll_number, students[i].student_name, students[i].percentage);
                }
                break;

            case 3:
                if (count == 0) {
                    printf("\n📭 No records available to generate marksheet.\n");
                    break;
                }
                printf("\nEnter Roll Number to generate marksheet: ");
                if (scanf("%d", &search_roll) != 1) {
                    printf("❌ Invalid Roll Number format!\n");
                    while (getchar() != '\n');
                    break;
                }

                found = 0;
                for (int i = 0; i < count; i++) {
                    if (students[i].roll_number == search_roll) {
                        printf("\n========================================\n");
                        printf("               MARKSHEET                \n");
                        printf("========================================\n");
                        printf("Roll Number  : %d\n", students[i].roll_number);
                        printf("Student Name : %s\n", students[i].student_name);
                        printf("----------------------------------------\n");
                        printf("Mathematics  : %d / 100\n", students[i].marks[0]);
                        printf("Physics      : %d / 100\n", students[i].marks[1]);
                        printf("Chemistry    : %d / 100\n", students[i].marks[2]);
                        printf("----------------------------------------\n");
                        printf("Total Marks  : %d / 300\n", students[i].total_marks);
                        printf("Percentage   : %.2f%%\n", students[i].percentage);
                        printf("Final Grade  : %c\n", students[i].grade);
                        printf("========================================\n");
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("❌ Marksheet for Roll Number %d not found.\n", search_roll);
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
