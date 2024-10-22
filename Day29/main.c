// Check whether a character is an alphabet or not.
#include <stdio.h>
int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        printf("It's an alphabet.\n");
    } else {
        printf("It's not an alphabet.\n");
    }

    return 0;
}
