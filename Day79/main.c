// Check String Is Palindrome Or Not Using For Loop
#include <stdio.h>
#include <string.h>

void checkPalindrome(char str[]) {
    int length = strlen(str);
    int isPalindrome = 1; // Assume it's a palindrome

    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
    }

    if (isPalindrome)
        printf("The string is a palindrome.\n");
    else
        printf("The string is not a palindrome.\n");
}

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str); // Takes input (without spaces)

    checkPalindrome(str);

    return 0;
}
