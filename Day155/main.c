#include <stdio.h>

int main() {
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j <= 7; j++) {
            if ((i == 0 && j % 3 != 0) || 
                (i == 1 && j % 3 == 0) || 
                (i == 2) || 
                (i - j == 2) || 
                (i + j == 8))
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }
    return 0;
}