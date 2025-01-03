#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSegment(char *segment) {
    int length = strlen(segment);
    if (length == 0 || length > 3) return false;
    if (segment[0] == '0' && length > 1) return false;
    int num = atoi(segment);
    return num >= 0 && num <= 255;
}

void generateIPAddresses(char *input) {
    int n = strlen(input);
    if (n > 12) {
        printf("Input string is too long for a valid IP address.\n");
        return;
    }

    for (int i = 1; i < n && i < 4; i++) {
        for (int j = i + 1; j < n && j < i + 4; j++) {
            for (int k = j + 1; k < n && k < j + 4; k++) {
                char part1[4], part2[4], part3[4], part4[4];
                strncpy(part1, input, i);
                part1[i] = '\0';
                strncpy(part2, input + i, j - i);
                part2[j - i] = '\0';
                strncpy(part3, input + j, k - j);
                part3[k - j] = '\0';
                strncpy(part4, input + k, n - k);
                part4[n - k] = '\0';
                if (isValidSegment(part1) && isValidSegment(part2) && isValidSegment(part3) && isValidSegment(part4)) {
                    printf("%s.%s.%s.%s\n", part1, part2, part3, part4);
                }
            }
        }
    }
}

int main() {
    char input[50];
    printf("Enter the string to generate IP addresses: ");
    scanf("%49s", input);
    generateIPAddresses(input);
    return 0;
}
