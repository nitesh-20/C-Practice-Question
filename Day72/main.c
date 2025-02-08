// Check whether a number is even or odd using a switch case.
#include <stdio.h>

int main() {
    int num;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Using switch case to check even or odd
    switch (num % 2) {
        case 0:
            printf("%d is Even.\n", num);
            break;
        case 1:
        case -1: // To handle negative numbers correctly
            printf("%d is Odd.\n", num);
            break;
    }

    return 0;
}
