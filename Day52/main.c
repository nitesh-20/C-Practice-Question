// Number Is Divisible By 11 Using (VEDIC MATH)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isDivisibleBy11(const char *number) {
    int oddSum = 0, evenSum = 0;
    
    for (int i = 0; number[i] != '\0'; i++) {
        int digit = number[i] - '0'; 
        if (i % 2 == 0) {
            oddSum += digit; 
        } else {
            evenSum += digit; 
        }
    }
    
    return (abs(oddSum - evenSum) % 11 == 0);
}

int main() {
    char number[100];
    
    printf("Enter a number: ");
    scanf("%s", number);
    
    if (isDivisibleBy11(number)) {
        printf("The number %s is divisible by 11.\n", number);
    } else {
        printf("The number %s is not divisible by 11.\n", number);
    }
    
    return 0;
}

