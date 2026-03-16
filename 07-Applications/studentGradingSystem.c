#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

int main() {
    int num_students, num_subjects;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    printf("Enter the number of subjects: ");
    scanf("%d", &num_subjects);

    int marks[num_students][num_subjects];
    float total_marks[num_students];
    float percentage[num_students];
    char name[num_students][MAX_NAME_LENGTH];

    for (int i = 0; i < num_students; i++) {
        printf("Enter name for student %d: ", i + 1);
        scanf("%s", name[i]);
        total_marks[i] = 0;
        for (int j = 0; j < num_subjects; j++) {
            printf("Enter marks for student %s in subject %d: ", name[i], j + 1);
            scanf("%d", &marks[i][j]);
            total_marks[i] += marks[i][j];
        }
    }

    for (int i = 0; i < num_students; i++) {
        percentage[i] = (total_marks[i] / (num_subjects * 100.0)) * 100;
        printf("Student %s: Total marks = %.2f, Percentage = %.2f%%\n", name[i], total_marks[i], percentage[i]);

        if (percentage[i] >= 90) {
            printf("Grade: A\n");
        } else if (percentage[i] >= 80) {
            printf("Grade: B\n");
        } else if (percentage[i] >= 70) {
            printf("Grade: C\n");
        } else if (percentage[i] >= 60) {
            printf("Grade: D\n");
        } else {
            printf("Grade: F\n");
        }
    }

    char check_name[MAX_NAME_LENGTH];
    printf("Enter the name of the student to check pass/fail status: ");
    scanf("%s", check_name);

    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (strcmp(name[i], check_name) == 0) {
            found = 1;
            if (percentage[i] >= 60) {
                printf("Student %s has passed.\n", check_name);
            } else {
                printf("Student %s has failed.\n", check_name);
            }
            break;
        }
    }

    if (!found) {
        printf("Student %s not found.\n", check_name);
    }

    return 0;
}
