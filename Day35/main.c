// Count the total number of notes in a given amount.
#include <stdio.h>
int main() {
    int amount;
    int notes2000, notes500, notes200, notes100, notes50, notes20, notes10, notes5, notes2, notes1;


    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Calculate the number of notes of each denomination
    notes2000 = amount / 2000;
    amount %= 2000;

    notes500 = amount / 500;
    amount %= 500;

    notes200 = amount / 200;
    amount %= 200;

    notes100 = amount / 100;
    amount %= 100;

    notes50 = amount / 50;
    amount %= 50;

    notes20 = amount / 20;
    amount %= 20;

    notes10 = amount / 10;
    amount %= 10;

    notes5 = amount / 5;
    amount %= 5;

    notes2 = amount / 2;
    amount %= 2;

    notes1 = amount;  // Remaining amount will be the number of 1 rupee notes

    // Display the result
    printf("2000 Rs notes: %d\n", notes2000);
    printf("500 Rs notes: %d\n", notes500);
    printf("200 Rs notes: %d\n", notes200);
    printf("100 Rs notes: %d\n", notes100);
    printf("50 Rs notes: %d\n", notes50);
    printf("20 Rs notes: %d\n", notes20);
    printf("10 Rs notes: %d\n", notes10);
    printf("5 Rs notes: %d\n", notes5);
    printf("2 Rs notes: %d\n", notes2);
    printf("1 Rs notes: %d\n", notes1);

    return 0;
}
