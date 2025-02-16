// Reverse a Number
#include <stdio.h>

int main() {
    int n, rev = 0, remainder;

    // Input a number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Reverse the number
    while (n != 0) {
        remainder = n % 10;   // Extract last digit
        rev = rev * 10 + remainder; // Append to reversed number
        n /= 10;   // Remove last digit
    }

    // Print the reversed number
    printf("Reversed Number: %d\n", rev);
    return 0;
}
