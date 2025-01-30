// Find the maximum between two numbers using the switch case.
#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch ((a > b) - (a < b)) {
        case 1:
            printf("Maximum: %d\n", a);
            break;
        case -1:
            printf("Maximum: %d\n", b);
            break;
        case 0:
            printf("Both numbers are equal\n");
            break;
    }

    return 0;
}
