// Find A Grade Of Given Marks or (Find a Grade of Given Marks Using Switch Case)
#include <stdio.h>

int main() {
    int marks, grade;

    printf("Enter your marks (0-100): ");
    scanf("%d", &marks);

    if (marks < 0 || marks > 100) {
        printf("Invalid marks! Please enter a value between 0 and 100.\n");
        return 1;
    }

    grade = marks / 10;

    switch (grade) {
        case 10:
        case 9:
            printf("Grade: A\n");
            break;
        case 8:
            printf("Grade: B\n");
            break;
        case 7:
            printf("Grade: C\n");
            break;
        case 6:
            printf("Grade: D\n");
            break;
        default:
            printf("Grade: F\n");
    }

    return 0;
}
