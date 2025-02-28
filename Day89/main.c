// Copy all elements from an array to another array.
#include <stdio.h>

int main() {
    int source[] = {1, 2, 3, 4, 5};
    int size = sizeof(source) / sizeof(source[0]);
    int destination[size];

    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }

    printf("Copied Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", destination[i]);
    }

    return 0;
}
