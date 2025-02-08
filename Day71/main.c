// Find the maximum between two numbers using the switch case
#include <stdio.h>

int main() {
    int num1, num2;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    // Using switch to find maximum
    switch (num1 > num2) {
        case 1:
            printf("Maximum: %d\n", num1);
            break;
        case 0:
            switch (num1 < num2) {
                case 1:
                    printf("Maximum: %d\n", num2);
                    break;
                case 0:
                    printf("Both numbers are equal.\n");
                    break;
            }
            break;
    }

    return 0;
}
