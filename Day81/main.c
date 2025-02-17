// Convert All Input String Simultaneously Into Asterisk ( * )
#include <stdio.h>

int main() {
    char str[100];
    
    printf("Enter a string: ");
    scanf("%s", str);  // Takes input (stops at space)
    
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = '*';
    }

    printf("Converted: %s\n", str);
    return 0;
}
