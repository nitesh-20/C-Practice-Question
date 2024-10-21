// Check whether a number is divisible by 5 and 11 or not.
#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if (num % 5 == 0) {
        printf("%d is divisible by 5.\n", num);
    } else {
        printf("%d is not divisible by 5.\n", num);
    }

    if (num % 11 == 0) {
        printf("%d is divisible by 11.\n", num);
    } else {
        printf("%d is not divisible by 11.\n", num);
    }

    return 0;
}

