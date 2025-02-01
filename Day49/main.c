// Count the Number of Digits of an Integer
#include <stdio.h>

int countDigits(int number) {
    int count = 0;
    if (number < 0) {
        number = -number;
    }
    
    do {
        count++;
        number /= 10;
    } while (number != 0);
    return count;
}

int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("The number of digits in %d is: %d\n", number, countDigits(number));
    return 0;
}
