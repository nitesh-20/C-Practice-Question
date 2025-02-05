// Find the maximum between two numbers using the switch case.
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch (a > b) {
        case 1:
            printf("Maximum is: %d\n", a);
            break;
        case 0:
            switch (a < b) {
                case 1:
                    printf("Maximum is: %d\n", b);
                    break;
                default:
                    printf("Both numbers are equal.\n");
            }
            break;
    }

    return 0;
}
